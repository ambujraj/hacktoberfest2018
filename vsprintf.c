/* This File is Part of LibFalcon.

 * Copyright (c) 2018, Syed Nasim
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.

   * Neither the name of LibFalcon nor the names of its
     contributors may be used to endorse or promote products derived from
     this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <stdarg.h>
#include <string.h>

#define is_digit(c) ((c) >= '0' && (c) <= '9')

static int skip_atoi(const char **s) {
  int i = 0;

  while (is_digit(**s))
    i = i * 10 + *((*s)++) - '0';
  return i;
}

#define ZEROPAD 1
#define SIGN 2
#define PLUS 4
#define SPACE 8
#define LEFT 16
#define SPECIAL 32
#define SMALL 64

#define do_div(n, base)                                                        \
  ({                                                                           \
    int __res;                                                                 \
    __asm__("divl %4" : "=a"(n), "=d"(__res) : "0"(n), "1"(0), "r"(base));     \
    __res;                                                                     \
  })

static char *number(char *str, int num, int base, int size, int precision,
                    int type) {
  char c, sign, tmp[36];
  const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int i;

  if (type & SMALL)
    digits = "0123456789abcdefghijklmnopqrstuvwxyz";
  if (type & LEFT)
    type &= ~ZEROPAD;
  if (base < 2 || base > 36)
    return 0;
  c = (type & ZEROPAD) ? '0' : ' ';
  if (type & SIGN && num < 0) {
    sign = '-';
    num = -num;
  } else
    sign = (type & PLUS) ? '+' : ((type & SPACE) ? ' ' : 0);
  if (sign)
    size--;
  if (type & SPECIAL)
    if (base == 16)
      size -= 2;
    else if (base == 8)
      size--;
  i = 0;
  if (num == 0)
    tmp[i++] = '0';
  else
    while (num != 0)
      tmp[i++] = digits[do_div(num, base)];
  if (i > precision)
    precision = i;
  size -= precision;
  if (!(type & (ZEROPAD + LEFT)))
    while (size-- > 0)
      *str++ = ' ';
  if (sign)
    *str++ = sign;
  if (type & SPECIAL)
    if (base == 8)
      *str++ = '0';
    else if (base == 16) {
      *str++ = '0';
      *str++ = digits[33];
    }
  if (!(type & LEFT))
    while (size-- > 0)
      *str++ = c;
  while (i < precision--)
    *str++ = '0';
  while (i-- > 0)
    *str++ = tmp[i];
  while (size-- > 0)
    *str++ = ' ';
  return str;
}

int vsprintf(char *buf, const char *fmt, va_list args) {
  int len;
  int i;
  char *str;
  char *s;
  int *ip;

  int flags;

  int field_width;
  int precision;
  int qualifier;

  for (str = buf; *fmt; ++fmt) {
    if (*fmt != '%') {
      *str++ = *fmt;
      continue;
    }

    flags = 0;
  repeat:
    ++fmt;
    switch (*fmt) {
    case '-':
      flags |= LEFT;
      goto repeat;
    case '+':
      flags |= PLUS;
      goto repeat;
    case ' ':
      flags |= SPACE;
      goto repeat;
    case '#':
      flags |= SPECIAL;
      goto repeat;
    case '0':
      flags |= ZEROPAD;
      goto repeat;
    }

    field_width = -1;
    if (is_digit(*fmt))
      field_width = skip_atoi(&fmt);
    else if (*fmt == '*') {

      field_width = va_arg(args, int);
      if (field_width < 0) {
        field_width = -field_width;
        flags |= LEFT;
      }
    }

    precision = -1;
    if (*fmt == '.') {
      ++fmt;
      if (is_digit(*fmt))
        precision = skip_atoi(&fmt);
      else if (*fmt == '*') {

        precision = va_arg(args, int);
      }
      if (precision < 0)
        precision = 0;
    }

    qualifier = -1;
    if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L') {
      qualifier = *fmt;
      ++fmt;
    }

    switch (*fmt) {
    case 'c':
      if (!(flags & LEFT))
        while (--field_width > 0)
          *str++ = ' ';
      *str++ = (unsigned char)va_arg(args, int);
      while (--field_width > 0)
        *str++ = ' ';
      break;

    case 's':
      s = va_arg(args, char *);
      len = strlen(s);
      if (precision < 0)
        precision = len;
      else if (len > precision)
        len = precision;

      if (!(flags & LEFT))
        while (len < field_width--)
          *str++ = ' ';
      for (i = 0; i < len; ++i)
        *str++ = *s++;
      while (len < field_width--)
        *str++ = ' ';
      break;

    case 'o':
      str = number(str, va_arg(args, unsigned long), 8, field_width, precision,
                   flags);
      break;

    case 'p':
      if (field_width == -1) {
        field_width = 8;
        flags |= ZEROPAD;
      }
      str = number(str, (unsigned long)va_arg(args, void *), 16, field_width,
                   precision, flags);
      break;

    case 'x':
      flags |= SMALL;
    case 'X':
      str = number(str, va_arg(args, unsigned long), 16, field_width, precision,
                   flags);
      break;

    case 'd':
    case 'i':
      flags |= SIGN;
    case 'u':
      str = number(str, va_arg(args, unsigned long), 10, field_width, precision,
                   flags);
      break;

    case 'n':
      ip = va_arg(args, int *);
      *ip = (str - buf);
      break;

    default:
      if (*fmt != '%')
        *str++ = '%';
      if (*fmt)
        *str++ = *fmt;
      else
        --fmt;
      break;
    }
  }
  *str = '\0';
  return str - buf;
}
