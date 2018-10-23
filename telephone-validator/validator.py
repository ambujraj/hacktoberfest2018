import re

def tel_num_validator(telephone_number):
    # Checks to see if input is a valid telephone number
	return re.search("^\(?([0-9]{3})\)?[-.●]?([0-9]{3})[-.●]?([0-9]{4})$",telephone_number)

if __name__ == "__main__":
	telephone_number = input("Telephone Number: ")
	try:
		phone=tel_num_validator(telephone_number)[0]
	except Exception :
		print ("Incorrect")
