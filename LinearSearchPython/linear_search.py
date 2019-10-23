#!usr/bin/env python
#-*- coding: utf-8 -*-

from datetime import datetime

def search(n, arr):
    start_time = datetime.now()
    index = None
    for element in arr:
        if element == n:
            index = arr.index(element)
    print "linear search interative mode executed in {}".format(datetime.now() - start_time)
    return index

def recursive(n, arr):
    start_time = datetime.now()
    if not arr:
        return
    if arr[0] == n:
        print "linear search recursive mode executed in {}".format(datetime.now() - start_time)
        return n
    else:
        arr.pop(0)
        return recursive(n, arr)