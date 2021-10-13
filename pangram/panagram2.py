##Panagram that doesn't allow repetition of letters

import string

def panagram():
    sentence = input()
    sentence = sentence.lower()
    dictionary = list(map(str, string.ascii_lowercase))

    pana = True
    for letter in sentence:
        if letter in string.ascii_lowercase and letter not in dictionary:
            pana = False
            break
        elif letter in list(map(str, string.ascii_lowercase)):
            dictionary.remove(letter)
        print(letter)

    if len(dictionary) == 0 and pana:
        print("Is a panagram")
    else:
        print("Not a panagram")

panagram()