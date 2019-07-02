#A python program to illustrate Caesar Cipher Technique 
def encrypt(text, s): 
	result = "" 
	# traverse text 
	for i in range(len(text)): 
		charct = text[i] 
		if(charct==","):
			result += ","
		elif(charct==";"):
			result += ";"
		elif(charct==":"):
			result += ":"
		elif(charct=="?"):
			result += "?"
		# Encrypt uppercase characters 
		elif (charct.isupper()):
			result += chr((((ord(charct) - 65)*s) % 26) + 65) 
		# Encrypt lowercase characters  
		else:
			result += chr((((ord(charct) - 97)*s) % 26) + 97) 
	
	return result 

#check the above function 
text = "b"
s = 3
print ("Text  : " + text)
print ("Shift : " + str(s))
print ("Cipher: " + encrypt(text,s))


#def encrypt(filename, key):
#	f = open('LincolnGA1.txt','r')
#	message = f.read()
#	for String in message:
#		
#
#		
#	f.close()
	
	
