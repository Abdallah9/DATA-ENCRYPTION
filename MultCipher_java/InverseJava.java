
class Untitled {
	
	// Returns modulo inverse of a with 
	// respect to m using extended Euclid 
	// Algorithm Assumption: nr1 and nr2 are 
	// coprimes, i.e., gcd(a, m) = 1 
	static int modInverse(int nr1, int nr2) 
	{ 
		int m = nr2; 
		int y = 0, x = 1; 
		String z = none;

		if (nr2 == 1) 
			return 0; 

		while (nr1 > 1) 
		{ 
//			if(nr2 == 0){
//				return 
//			}
			// q is quotient 
			int q = nr1 / nr2;
			int t = nr2; 
			// nr2 is remainder now, process 
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
		
		int a = 8 , m = 26; 
	
		System.out.println("Modular multiplicative " + "inverse is " + modInverse(a, m)); 
		
	}
}



//class GFG { 
//	// extended Euclidean Algorithm 
//	public static int gcdExtended(int a, int b, int x, int y) 
//	{ 
//		// Base Case 
//		if (a == 0) { 
//			x = 0; 
//			y = 1; 
//			return b; 
//		} 
//
//		int x1 = 1, y1 = 1; // To store results of recursive call 
//		int gcd = gcdExtended(b % a, a, x1, y1); 
//
//		// Update x and y using results of recursive 
//		// call 
//		x = y1 - (b / a) * x1; 
//		y = x1; 
//
//		return gcd; 
//	} 
//	
//	
//	public static int inverseNr (int nr1, int N1)
//	{
//		int d, x=1, y=1;  // d=gcd(nr1, nr2)
//		
//		d=gcdExtended (N1, nr1, x, y);
//		
//		if (d != 1)
//		{
//			
//			System.out.print("ERROR: The Inverse DOESN'T exist!");
//			return 0;
//		}
//		
//		if (y<0) 
//		y=y+N1;
//
//		return y;
//	}
//
//	// Driver Program 
//	public static void main(String[] args) 
//	{ 
//		int x = 1, y = 1; 
//		int a = 3, b = 26; 
//		int g = inverseNr(a, b); 
//		System.out.print(g); 
//	} 
//} 


