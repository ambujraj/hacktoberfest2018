
# given mobile number is valid 
import re 

def isValid(s): 
	

	Pattern = re.compile("(0/91)?[7-9][0-9]{9}") 
	return Pattern.match(s) 

# Driver Code 
s = "676464646776674545"
if (isValid(s)): 
	print ("Valid Number")	 
else : 
	print ("Invalid Number") 


