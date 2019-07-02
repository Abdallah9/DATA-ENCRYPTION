

#def encrypt(filename,key):
#
#	with open(filename, 'r') as f:
#		with open(filename, 'w') as outf:
#			
#			data = f.readline()
#			for line in data:
#				if (line == ","):
#					data += ","
#				elif(line.isupper()):
#					data += chr((((ord(line) - 65)*key) % 26) + 65)
#				else:
#					data += chr((((ord(line) - 97)*key) % 26) + 97) 
#			return outf.write(data)
#			filename.close()
#			
#			
#encrypt('LincolnGA1.txt', 3)
#


#invKey = input()
#print(invKey)

#def encryptFile(filename, s):
#	relt = ""   # Creates an array of length 26 containing all 0s.
#	f = open(filename, 'r')
#	rdAll = f.read()
#	f.close()
#	for c in rdAll:
##		if(c == ' '):
##			relt = ' '
##		elif(c == ','):
##			relt == ','
#		if(c.isupper()):
#			relt += chr((((ord(c) - 65)*s) % 26) + 65)
#		else:
#			relt += chr((((ord(c) - 65)*s) % 26) + 65) 
#	return relt
#
#
##'LincolnGA1.txt'
#
#encryptFile('test.txt', 3)


			


def gcd(a, b):
# Return the GCD of a and b using Euclid's Algorithm
	while a != 0:
		a, b = b % a, a
	return b


def findModInverse(a, m):
# Returns the modular inverse of a % m, which is
# the number x such that a*x % m = 1
	if gcd(a, m) != 1:
		return None # no mod inverse if a & m aren't relatively prime
	# Calculate using the Extended Euclidean Algorithm:
	u1, u2, u3 = 1, 0, a
	v1, v2, v3 = 0, 1, m
	
	while v3 != 0:
		q = u3 // v3 # // is the integer division operator
		v1, v2, v3, u1, u2, u3 = (u1 - q * v1), (u2 - q * v2), (u3 - q * v3), v1, v2, v3
	return u1 % m



mod = findModInverse(8, 26)


print(mod)











