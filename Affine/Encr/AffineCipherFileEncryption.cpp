//Abdallah Chidjou
//Affine Cipher Encryption

#include <iostream>
#include <cstring>  // strlen()
#include <fstream>
using namespace std;

int main()
{
	int key, key1, counter=0;  // encryption factor
	const int SIZE=1000;
	char letter, om[SIZE];  // om=originalMessage
	char em[SIZE];  		// em=encryptedMessage

	cout<<"Enter key: ";
	cin>>key;
	
	cout<<"Enter the affine key: ";
	cin>>key1;


	ifstream inFile;
	ofstream outFile;

	inFile.open("LincolnGA1.txt");
	if (inFile.is_open())
	{
		while(!inFile.eof()){
			
			inFile.get(letter);  // gets one letter

			if (letter == 32)  // 32 is 'space' in ASCII
			{
				em[counter]=32;
				cout<<" ";
			}
			else if (letter == 44)  // 44 is 'coma' in ASCII
			{
				em[counter]=44;
				cout<<",";
			}
			else if (letter == 46)  // 46 is '.' in ASCII
			{
				em[counter]=46;
				cout<<".";
			}
			else
			{
				int index = (((letter-'a')*key) + key1)%26;
				em[counter]=(char)(index + 'a');
			}
			counter++;
		} // end while
		inFile.close();	
	} // end if
	
	outFile.open("encryptedLincolnGA1.txt");
	
	if (outFile.is_open())
	{	
		for (int i=0; i<counter; i++)
		{
			outFile<<em[i];
		}
	}
	
	outFile.close();	
	
	cout<<endl<<endl;
}

