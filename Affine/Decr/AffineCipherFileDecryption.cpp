//Abdallah Chidjou
//Affine Cipher Decryption

#include <iostream>
#include <cstring>  // strlen()
#include <fstream>
using namespace std;

int eea(int nr1, int nr2, int &x, int &y);
int inverseNr (int nr1, int N1);


int main()
{
	int inverseKey, counter=0;  
	int key, key1;
	int modkey = 26;
	
	const int SIZE=1000;
	char letter, dm[SIZE];  // dm=decryptedMessage
	char em[SIZE];  // em=encryptedMessage
	
	

	cout<<"Enter the original key to decript the message: ";
	cin>>key;
	
	cout<<"Enter the original affine key: ";
	cin>>key1;
	
	inverseKey = inverseNr(key, modkey);

	ifstream inFile;
	ofstream outFile;
	
	inFile.open("encryptedLincolnGA1.txt");
	if (inFile.is_open())
	{
		while(!inFile.eof()){
			
			inFile.get(letter);  // gets one letter

			if (letter == 32)  // 32 is 'space' in ASCII
			{
				
				dm[counter]=32;
				cout<<" ";
			}
			else if (letter == 44)  // 44 is 'coma' in ASCII
			{
				dm[counter] = 44;
				cout<<",";
			}	
			else if (letter == 46)  // 46 is '.' in ASCII
			{
				dm[counter]=46;
				cout<<".";
			}   	  
			else
			{
				//encryptedText[i] = ((((originalText[i] - 'a')-key1)*invKey) %26) + 'a';
	
				int index = (((letter-'a')-key1)*inverseKey)%26;
				dm[counter]=(char)(index + 'a');	   	  	 
			}
			counter++;
		} // end while
		
		inFile.close();	
	} // end if
	

	outFile.open("decryptedLincolnGA1.txt");
	
	if (outFile.is_open())
	{	
		for (int i=0; i<counter; i++)
		{
			outFile<<dm[i];
		}
	}
	
	outFile.close();	
	
	cout<<endl<<endl;
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
