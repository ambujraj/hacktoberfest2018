#import reverse_string
def palindrome(string):
	num = len(string) - 1
	second_half = ''
	mid = len(string) - 1
	while (num > mid/2):
		second_half += string[num]
		num -=1

	first_half = string[:len(string)/2]
	if first_half == second_half:
		return True
	else:
		return False

print palindrome("racecar")
print palindrome("poop")
