import re


class TelephoneNumberValidator:

    def __init__(self, number):
        self.number = number

    def isnumber_valid(self):
        # 1) Begins with 0 or 91
        # 2) Then contains 7 or 8 or 9.
        # 3) Then contains 9 digits
        pattern = re.compile("(0/91)?[7-9][0-9]{9}")
        return pattern.match(self.number)


if __name__ == '__main__':
    number = "9876345213"
    tnv = TelephoneNumberValidator(number)

    if tnv.isnumber_valid():
        print("Telephone Number is Valid")
    else:
        print ("Telephone Number is not Valid")
