from time import sleep
from threading import Thread

def addVal(array, val):
    sleep(val)
    array.append(val)

def sort(array):
    result = []
    for val in array:
        Thread(target = addVal, args = (result, val)).start()
    while(1):
        sleep(1)
        if(len(result) == len(array)):
            return result
array = [2,1,5,3]
print(sort(array))
