/*  MultiplicationCipher_Matrix(A)(mod N)_encrypt_2x2_1a.cpp
- using routines from Cormen's book

Encryption:  E = A * M              (mod N)
Decryption:  M = Inverse(A) * E     (mod N)

INPUT:  abcdef (orig. msg), A=(1 2), N=27
							         (1 3)
							  
OUTPUT:  cdilot(encrypted msg)

*/

#include <iostream>
#include <cstring>  // strlen()
#include <cstdlib>  // exit()
using namespace std;

////////  main  //////////////////
int main()
{
char letters[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};

	char om[100];
	int i,j,n,N=27,col,rowNr=0,colNr=0;
	
	cout<<"Enter your message: ";
//   cin>>om;
	cin.getline(om,100);
	
	cout<<"\nom="<<om<<endl<<endl;
	
	n=strlen(om);
//   cout<<"\n n="<<n<<endl<<endl; 

	col=n;
	
	while (col%2 != 0)
	{
		  col++;
	}
	
	col=col/2;
	
	int em[2][col], sm[2][col];
	
	for (i=0; i<2; i++)
	{
		  for (j=0; j<col; j++)
		  {
		  	 em[i][j]=26;
		 	 sm[i][j]=26;	   
		  }
	}  
	
	for (i=0; i<n; i++)
	{
		  for (j=0; j<27; j++)
		  {
		  	 if (om[i]==letters[j])
		  	 {
		  	 	sm[rowNr][colNr] = j;
		  	 }	   
		  }
		  rowNr++;
		  
		  if (rowNr == 2)
		  {
		  	rowNr=0;
		  	colNr++;
		  }
	}  

	cout<<"sm[]="<<endl;
	for (i=0; i<2; i++)
	{
		  for (j=0; j<col; j++)
		  {
		 cout<<sm[i][j]<<" ";	   
		  }
		  cout<<endl;
	}     

	cout<<endl;
	
	///////////  Matrix A  ////////////////
	int A[2][2];
	
	cout<<"\nEnter 4 numbers in the matrix A[]: ";
	cin>>A[0][0]>>A[0][1]>>A[1][0]>>A[1][1];
	
	///////////  Encrypt  ////////////////   
	rowNr=0;
	colNr=0;
	
	for (int m=0; m<col*2; m++)
	{
		   int matNr=0;
		   
		   for (int k=0; k<2; k++)
		   {
		   	  matNr=matNr+(A[rowNr][k]*sm[k][colNr]);
		   }
		   
		   em[rowNr][colNr] = matNr;
		   
		   colNr++;
		   
		   if (colNr==col)
		   {
		   	  colNr=0;
		   	  rowNr++;
		   }
	}
	
	cout<<"\n\nem[]="<<endl;
	for (i=0; i<2; i++)
	{
		  for (j=0; j<col; j++)
		  {
		 cout<<em[i][j]<<" ";	   
		  }
		  cout<<endl;
	}     
	cout<<endl;
	
	cout<<"\nThe 'encrypted' message is:"<<endl;

	for (i=0; i<col; i++)
	{
		  for (j=0; j<2; j++)
		  {
		    cout<<letters[em[j][i]];	   
		  }
	}     
	cout<<endl;
	
}

