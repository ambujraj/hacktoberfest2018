# This is my favorite code snippet because it show how a simple conversion works under all computer process.


def decimal_to_binary(n):
    if n > 1:
        decimal_to_binary(n // 2)
    print(n % 2, end=' ')


if __name__ == '__main__':
    input_value = int(input('Enter decimal for the conversion:'))
    decimal_to_binary(input_value)
