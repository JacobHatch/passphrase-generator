### THIS IS INTENDED FOR GENERATING PASSPHRASES/PASSWORDS TO THEN BE MANUALLY ENTERED ### 

# Python program to create a secure pass-phrase that is also personalized and easy to
# remember. There is also an option to generate a secure password that is not
# personalized but definitely secure, using the ASCII table.

import random

# Obtain whether a password or passphrase will be created.
ans = input("\nWould you like to create a familiar passphrase or a randomly generated password?\nType 'phrase' or 'word' to choose and press enter.\n")

# This function takes a string as a parameter and returns a new, secured string by replacing the characters with symbols, numbers, or capital letters
# Requires:    A word or phrase lacking spaces in the form of string
# Assignable:  NONE
# Ensures:     Returns a secured version of the original word or phrase
def secure_item(item):

	passphrase = ''
	for stuff in range(len(item)):
		letter = item[stuff]
		rand = random.randint(0,2)
		if rand == 0:
			if letter == 's':
				passphrase += '$'
			elif letter == 'i':
				passphrase += '!'
			else:
				passphrase += letter.capitalize()
		if rand == 1:
			passphrase += letter
		if rand == 2:
			if letter == 'i':
				passphrase += '1'
			elif letter == 's':
				passphrase += '5'
			elif letter == 'p':
				passphrase += '9'
			elif letter == 'e':
				passphrase += '3'
			elif letter == 'o':
				passphrase += '0'
			elif letter == 'l':
				passphrase += '1'
			elif letter == 'b':
				passphrase += '8'
			else:
				passphrase += letter.capitalize()
	return passphrase

# If the decision was to create a passphrase
if ans == 'phrase':

	passphrase = ''
	print("\nYou have chosen to create a personalized passphrase.")
	print("To create a passphrase, you will use memorable information.\n")

	# Obtain the 4 parts of the familiar passphrase from user input
	pass_part1 = input("Type a memorable 5+ letter word.           ")
	pass_part3 = input("Type a memorable number.(of any length)    ")
	pass_part2 = input("Type a memorable 5+ letter word.           ")
	pass_part4 = input("Type a memorable phrase.(without spaces)   ")

	# Type cast the inputs to string, (this could probably be done in the same line as accpeting the input)
	s1, s2, i1, p1 = str(pass_part1), str(pass_part2), str(pass_part3), str(pass_part4)

	# Use the function to secure each input and add them to a single string that will be the final passphrase
	passphrase += secure_item(s1)
	passphrase += i1
	passphrase += secure_item(p1)
	passphrase += secure_item(s2)

	# Print the new, secure passphrase that is familiar to the inputs
	print(f"\nYour passphrase is: {passphrase}\n")

# If the decision was to create a password
if ans == 'word':

	password = ''
	print("\nYou have chosen to have a password generated for you.")

	# Obtain the length of the passowrd from user input
	length = input("How long would you like your password to be?\n(it is recommended at least 10 characters in length)\n")

	# Type cast the input to an integer, (this could probably be done in the same line as accepting the input)
	pass_length = int(length)
	print()

	# This loop loops as many times as the password length, each time generating a random ASCII character and adding it to the password
	for i in range(pass_length):

		# Generate a random number between 32 and 126, which is also the range of values of the ASCII printable characters
		rand = random.randint(32, 126)

		# Type cast the number to its character form
		password += chr(rand)

	# Print the secure password that has been generated to the specified length
	print(f"\nYour password is: {password}\n")
