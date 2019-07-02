//Abdallah Chidjou
//Affine Cipher Decryption

#include <iostream>

using namespace std;

int eea(int nr1, int nr2, int &x, int &y);
int inverseNr (int nr1, int N1);

// x= A’*(y-b) mod 26.

int main(int argc, char *argv[]) {
	
	int key, key1, invKey;
	int modkey = 26;
	const int SIZE = 50;
	char originalText[SIZE];
	char encryptedText[SIZE];
	
	

	
	cout << "Enter your message: ";
	cin >> originalText;
	
	cout << "Enter the original key: ";
	cin >> key;
	
	cout << "Enter the affine addition: ";
	cin >> key1;
	
	invKey = inverseNr(key, modkey);
	
	for (int i=0; i<strlen(originalText); i++){
		encryptedText[i] = ((((originalText[i] - 'a')-key1)*invKey) %26) + 'a';
	}
	
	cout << "\nThe original message is: " << endl;
	for (int i=0; i<strlen(originalText); i++){
			cout << encryptedText[i];
		}
	cout << endl;

	
}


////////  eea (Extended Euclidian Algorithm)  ///////////
int eea(int nr1, int nr2, int &x, int &y)
{
	if (nr2==0)
	{ 
		 x = 1;
		 y = 0;
		 return nr1;
	}
	
	int x1, y1, d;
	
	d = eea (nr2, nr1%nr2, x1, y1);
	
	x = y1;
	y = x1 - (nr1/nr2)*y1;
	return d;
}

//////////  inverseNr  ///////////
int inverseNr (int nr1, int N1)
{
	int d, x, y;  // d=gcd(nr1, nr2)
	
	d=eea (N1, nr1, x, y);
	
	if (d != 1)
	{
		  cout<<"ERROR: The Inverse DOESN'T exist!"<<endl;
		  return 0;
	}
	
	if (y<0) y=y+N1;
//  cout<<"\nd="<<d<<" x="<<x<<" y="<<y<<endl;
	
	return y;
}
