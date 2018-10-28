class Factorial:

    @staticmethod
    def get_factorial(num: int):
        if num == 0:
            return 1
        else:
            return num * Factorial.get_factorial(num - 1)
