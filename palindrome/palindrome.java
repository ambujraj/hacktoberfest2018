class Main {
  public static boolean isPalindrome(int number) {
    int temp = number;
    int reverse = 0;
    // 12321
    while (temp > 0) {
      reverse *= 10;
      reverse += temp % 10;
      temp /= 10;
    }

    if (reverse == number) return true;
    return false;
  }

  public static void main (String[] args) {
  }
}
