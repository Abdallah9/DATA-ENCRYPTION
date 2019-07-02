//Abdallah Chidjou
//Affine Cipher Encryption

#include <iostream>
#include <cstring>
using namespace std;
int main() 
{
	int key, key1;
	const int SIZE = 50;
	char originalText[SIZE];
	char encryptedText[SIZE];
	
	cout << "Enter your message: ";
	cin >> originalText;
	
	cout << "Enter your key: ";
	cin >> key;
	
	cout << "Enter your affine key: ";
	cin >> key1;
	
	for (int i=0; i<strlen(originalText); i++){
		encryptedText[i] = ((((originalText[i] - 'a')*key) + key1) %26) + 'a';
	}
	
	cout << "\nThe encrpted message is: " << endl;
	for (int i=0; i<strlen(originalText); i++){
			cout << encryptedText[i];
		}
	cout << endl;
}
