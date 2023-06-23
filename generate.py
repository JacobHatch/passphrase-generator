### THIS IS INTENDED FOR GENERATING PASSPHRASES/PASSWORDS TO THEN BE MANUALLY ENTERED ### 

# Python program to create a secure pass-phrase that is also personalized and easy to
# remember. There is an option to generate a secure password that is not
# personalized but definitely secure.

import random

ans = input("\nWould you like to create a familiar passphrase or a randomly generated password?\nType 'phrase' or 'word' to choose and press enter.\n")

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
	
if ans == 'phrase':
	
	print("\nYou have chosen to create a personalized passphrase.")
	print("To create a passphrase, you will use memorable information.\n")

	pass_part1 = input("Type a memorable 5+ letter word.          ")
	pass_part3 = input("Type a memorable number.(of any length)   ")
	pass_part2 = input("Type a memorable 5+ letter word.          ")
	pass_part4 = input("Type a memorable phrase.(without spaces)  ")

	s1, s2, i1, p1 = str(pass_part1), str(pass_part2), str(pass_part3), str(pass_part4)
	
	passphrase = ''

	passphrase += secure_item(s1)
	passphrase += i1
	passphrase += secure_item(p1)
	passphrase += secure_item(s2)
	
	print(f"\nYour passphrase is: {passphrase}\n")

if ans == 'word':
	print("\nYou have chosen to have a password generated for you.")
	length = input("How long would you like your password to be?\n(it is recommended at least 10 characters in length)\n")
	pass_length = int(length)
	print()
	
	password = ''

	for i in range(pass_length):
		rand = random.randint(32, 126)
		password += chr(rand)

	print(f"\nYour password is: {password}\n")
