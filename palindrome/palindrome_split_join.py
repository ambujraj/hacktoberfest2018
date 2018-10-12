"""
A version of palindrome with more documentation
so beginners can see what is happening step by step.

Author: Collin Cates
"""

def is_palindrome():
	"""Check if a word is a palindrome"""

	# Ask user for a word, then make the word lowercase
	word = input("Enter a word: ").lower()

	# Use list comprehension on word
	letters = [letter for letter in word]

	# Reverse the list of letters
	reversed_letters = letters[::-1]

	# Join the reversed letters into a reversed word
	reversed_word = ''.join(reversed_letters)

	# Compare word to reversed_word
	if word == reversed_word:
		print(f"\n{word} is a palindrome!\n")
	else:
		print(f"\n{word} is not a palindrome.\n")


if __name__ == "__main__":
	is_palindrome()
