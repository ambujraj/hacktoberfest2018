import random
while True:
    print("Rolling the dice:",random.randint(1,6))
    repeat =input("Do you wanna roll again y/n?")
    if repeat != "y":
        break
