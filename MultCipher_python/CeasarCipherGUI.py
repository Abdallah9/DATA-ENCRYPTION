#import tkinter as tk
from tkinter import *
#from tkinter import ttk 
from tkinter import scrolledtext

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
	
#def encrypt(text,s): 
#	result = "" 
#	# traverse text 
#	for i in range(len(text)): 
#		charct = text[i] 
#		# Encrypt uppercase characters 
#		if (charct.isupper()):
#			result += chr((ord(charct) + s-65) % 26 + 65) 
#		# Encrypt lowercase characters 
#		else: 
#			result += chr((ord(charct) + s - 97) % 26 + 97) 
#	return result 
	
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
	
#def decrypt(text,s): 
#	result = "" 
#	# traverse text 
#	for i in range(len(text)): 
#		char = text[i] 
#		# Encrypt uppercase characters 
#		if (char.isupper()):
#			result += chr((ord(char) - s-65) % 26 + 65) 
#		# Encrypt lowercase characters 
#		else: 
#			result += chr((ord(char) - s - 97) % 26 + 97) 
#	return result 
	



def display0(event = None):
	#global scr1
	#global keyEntered
	textIn = scr1.get(1.0, END)
	key = int(keyEntered.get())
	passfunct = encrypt(textIn, key)
	#print(passfunct)
	scr2.insert(END, passfunct)
	
def display1(event = None):
	#global scr3
	#global keyEntered
	textIn1 = scr3.get(1.0, END)
	key1 = int(keyEntered.get())
	passfunct1 = decrypt(textIn1, key1)
	#print(passfunct)
	scr4.insert(END, passfunct1)
	

	
win = Tk() # 2 Create instance
win.title("Ceasar Cipher GUI") # 3 Add a title

win.resizable(100, 100) # 4 Disable resizing the GUI


aLabel1 = Label(win, text="Message ")
aLabel1.grid(column=0, row=0)

scr1 = scrolledtext.ScrolledText(win, width=30, height=3, wrap=WORD)
scr1.grid(column=0, row=10, columnspan=10)




aLabel2 = Label(win, text="Encrypted Msg ")
aLabel2.grid(column=29, row=0)

scr2 = scrolledtext.ScrolledText(win, width=30, height=3, wrap=WORD)
scr2.grid(column=28, row=10, columnspan=10)



aLabelkey = Label(win, text="key ")
aLabelkey.grid(column=15, row=17)
keyEntered = Entry(win, width=5, textvariable=IntVar())
keyEntered.grid(column=19, row=17) 



aLabel3 = Label(win, text="Encrpted Message ")
aLabel3.grid(column=0, row=40)

scr3 = scrolledtext.ScrolledText(win, width=30, height=3, wrap=WORD)
scr3.grid(column=0, row=60, columnspan=10)


aLabel4 = Label(win, text="Original Msg ")
aLabel4.grid(column=29, row=40)

scr4 = scrolledtext.ScrolledText(win, width=30, height=3, wrap=WORD)
scr4.grid(column=28, row=60, columnspan=20)


bt1 = Button(win, text="Ecrypt")
bt1.grid(row=17, column=0)
bt1.bind('<Button>', display0)


bt2 = Button(win, text="Decrypt")
bt2.grid(row=65, column=0)
bt2.bind('<Button>',display1)

mainloop() 