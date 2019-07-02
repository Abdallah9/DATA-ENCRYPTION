
def modInverse(nr1, nr2) : 
	m0 = nr2 
	y = 0
	x = 1
	if (nr2 == 1) : 
		return 0
	while (nr1 > 1): 
		if(nr2 == 0):
			return None
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



# Driver program to test above function 
a = 8
m = 26
print("Modular multiplicative inverse is", 
	modInverse(a, m)) 

# This code is contributed by Nikita tiwari. 
