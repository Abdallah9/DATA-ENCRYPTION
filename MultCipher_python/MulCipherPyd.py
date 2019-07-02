#A python program to illustrate Caesar Cipher Technique 
def decrypt(text, key): 
	#print("Enter the original key to decript the message.")
	#key = input()
	modkey = 26
	invkey = modInverse(key, modkey)
	
	result = "" 
	# traverse text 
	for i in range(len(text)): 
		charct = text[i] 
		if(charct==","):
			result += ","
		elif(charct==";"):
			result += ";"
		elif(charct=="'"):
			result += "'"
		elif(charct==":"):
			result += ":"
		elif(charct=="?"):
			result += "?"
		# Encrypt uppercase characters 
		elif(charct.isupper()):
			result += chr((((ord(charct) - 65)*invkey) % 26) + 65) 
		# Encrypt lowercase characters  
		else:
			result += chr((((ord(charct) - 97)*invkey) % 26) + 97) 
	
	return result

#		# Encrypt uppercase characters 
#		if (char.isupper()):
#			result += chr((ord(char) - s-65) % 26 + 65) 
#
#		# Encrypt lowercase characters 
#		else: 
#			result += chr((ord(char) - s - 97) % 26 + 97) 
#
#	return result 
	
def modInverse(nr1, nr2) : 
	m0 = nr2 
	y = 0
	x = 1
	if (nr2 == 1) : 
		return 0
	while (nr1 > 1): 
		if(nr2 == 0):
			print("The inverse doesn't exist.")
		# q is quotient 
		q = nr1 // nr2
#		if(q==0):
#			print("The inverse doesn't exist")
		t = nr2 
		# m is remainder now, process 
		# same as Euclid's algo 
		nr2 = nr1 % nr2 
		nr1 = t 
		t = y 
		# Update x and y 
		y = x - q * y 
		x = t 
	# Make x positive 
	if (x < 0) : 
		x = x + m0 
	return x 

#check the above function 
text = "b"
s = 3
print ("Text  : " + text)
print ("Shift : " + str(s))
print ("Cipher: " + decrypt(text,s))