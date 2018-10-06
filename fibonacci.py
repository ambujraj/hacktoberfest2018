'''
This module adds a fib function that will allow a user to enter a number of entries that would like returned
'''

def fib(count):
    try:
        count = int(count)
    except:
        print("Please enter a value that represents a number as the argument")
        print("Ex: fib('2')")
        print("Ex: fib(True)")
        print("Ex: fib(-3)")
        return []
    count = count - 2
    if count < 0:
        print("Please enter a number greater than or equal to 2")
        return []
    fib_list = [1,1]
    for i in range(count):
        if i == count:
            return fib_list
        else:
            fib_list.append(fib_list[-1] + fib_list[-2])
    return fib_list

print('fib list: {}'.format(fib(37)))
