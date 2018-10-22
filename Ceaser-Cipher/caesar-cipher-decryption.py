message = input("Insert message to decrypt: ").lower()
key = int(input("Insert key: "))
size = len(message)
encrypted_message = ""
upperBound = ord('z')
lowerBound = ord('a')

for i in range(size):
    char = message[i]
    charValue = ord(char)

    if char == " ":
        #encrypted_message += char
        pass
    
    elif charValue - key < lowerBound:
        char = chr(charValue + upperBound - lowerBound)
        encrypted_message += char
        
    else:
        char = chr(charValue - key)
        encrypted_message += char

print(encrypted_message)
