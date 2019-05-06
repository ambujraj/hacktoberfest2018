message = input("Insert message to decrypt: ").lower()
key = int(input("Insert key: "))
size = len(message)
decrypted_message = ""
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
        decrypted_message += char
        
    else:
        char = chr(charValue - key)
        decrypted_message += char

print(decrypted_message)
