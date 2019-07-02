/*  MultiplicationCipher_encryption
- in this program we encrypt a message using the MultiplicationCipher

INPUT:  abcd  (original msg) 
OUTPUT: adgj  (encrypted msg)

*/

class MulCipherJava 
{  
	// Encrypts text using a shift od s 
	public static StringBuffer encrypt(String text, int s) 
	{ 
		StringBuffer result= new StringBuffer(); 

		for (int i=0; i<text.length(); i++) 
		{ 
			if (Character.isUpperCase(text.charAt(i))) 
			{ 
//				char ch = (char)(((int)text.charAt(i) + s - 65) % 26 + 65); 
				
				char ch = (char)(((((int)text.charAt(i) - 'A')*s) % 26) + 'A'); 
				result.append(ch); 
			} 
			else
			{ 
				char ch = (char)(((((int)text.charAt(i) - 'a')*s) % 26) + 'a'); 
				result.append(ch); 
			} 
		} 
		return result; 
	} 

	// Driver code 
	public static void main(String[] args) 
	{ 
		String text = "abc"; 
		int s = 2; 
				
		System.out.println("Text : " + text); 
		System.out.println("Shift : " + s); 
		System.out.println("Cipher: " + encrypt(text, s)); 
	} 
} 