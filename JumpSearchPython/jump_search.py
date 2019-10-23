#!usr/bin/env python
#-*- coding: utf-8 -*-

from math import sqrt
from datetime import datetime

def search(n, arr):
    start_time = datetime.now()
    size = len(arr)
    jump_block = int(sqrt(size))
    start, end = 0, jump_block
    
    while arr[end] < n:
        start = (end + 1)
        if size - (end + jump_block) < jump_block:
            end = (end + jump_block) + (size - (end + jump_block))
            break
        else:
            end = end + jump_block

    for x in arr[start:end]:
        if x == n:
            print "jump search interative mode executed in {}".format(datetime.now() - start_time)
            return n