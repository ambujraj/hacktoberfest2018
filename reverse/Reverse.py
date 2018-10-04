from __future__ import print_function
"""
Code by: Keshav Gupta
Edited By: Sanket Chaudhari
"""

def reverse(num_in):
    num_in = int(num); # In case of python3

    if(num_in < 0):
        return 0;
    else:
        num_in = str(num_in)[::-1];
        return int(num_in);

num = input("Enter the number to reverse: ")

print("Reversed Number:",reverse(num));
