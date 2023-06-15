# Python program to create a secure pass-phrase that is also personalized and easy to
# remember. There is an option to generate a secure password that is not
# personalized but definitely secure.

import random

print()
ans = input("Would you like to create a familiar passphrase or a randomly generated password?\nType 'phrase' or 'word' to choose and press enter.\n")

if ans == 'phrase':
	print()
	print("You have chosen to create a personalized passphrase.")
	print("To create a passphrase, you will use memorable information.")
	print()

	pass_part1 = input("Type a memorable 5+ letter word.        ")
	pass_part3 = input("Type a memorable number.(of any length)   ")
	pass_part2 = input("Type a memorable 5+ letter word.        ")
	pass_part4 = input("Type a memorable phrase.(without spaces)  ")

	s1 = str(pass_part1)
	s2 = str(pass_part2)
	i1 = str(pass_part3)
	p1 = str(pass_part4)

	passphrase = ''

	for stuff in range(len(s1)):
		letter = s1[stuff]
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

	passphrase += i1

	for stuff in range(len(p1)):
		letter = p1[stuff]
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

	for stuff in range(len(s2)):	
		letter = s2[stuff]
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
	
	print()
	print("Your passphrase is:", passphrase)

if ans == 'word':
	print()
	print("You have chosen to have a password generated for you.")
	
	buildrand = random.randint(15,21)
	password = ''

	for i in range(buildrand):
		rand = random.randint(32, 126)
		password += chr(rand)

	print()
	print("Your password is: ", password)
	print()
