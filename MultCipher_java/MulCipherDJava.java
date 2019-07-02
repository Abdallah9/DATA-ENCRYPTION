class Untitled {
	
	public static StringBuffer decrypt(String text, int key){
		
			StringBuffer result= new StringBuffer();
			int  modkey = 26;
			int invkey = modInverse(key, modkey);
			
			for (int i=0; i<text.length(); i++){
				
				if (Character.isUpperCase(text.charAt(i))){
						
					char ch = (char)(((((int)text.charAt(i) - 'A')*invkey) % 26) + 'A'); 
					result.append(ch); 
				} 
				else
				{ 
					char ch = (char)(((((int)text.charAt(i) - 'a')*invkey) % 26) + 'a'); 
					result.append(ch); 
				} 
			} 
			return result; 
		} 
	
	
	static int modInverse(int nr1, int nr2){
		int m = nr2; 
		int y = 0, x = 1; 

		if (nr2 == 1) 
			return 0; 
		while (nr1 > 1){
			// q is quotient 
			int q = nr1 / nr2;
			int t = nr2; 
			// m is remainder now, process 
			// same as Euclid's algo 
			nr2 = nr1 % nr2;
			nr1 = t; 
			t = y; 
			//if (m==0){
			//	System.out.println("No inv");			}
			// Update x and y 
			y = x - q * y; 
			x = t; 
		} 
		// Make x positive 
		if (x < 0) 
			x += m; 
		return x; 
	} 	
		
		
	public static void main(String[] args) {
		String text = "ans"; 
		int s = 9; 
		System.out.println("Text : " + text); 
		System.out.println("Shift : " + s); 
		System.out.println("Cipher: " + decrypt(text, s));
	}
}