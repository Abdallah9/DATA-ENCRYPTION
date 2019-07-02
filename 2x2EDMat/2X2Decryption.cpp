/*  MultiplicationCipher_Matrix(A)(mod N)_decrypt_2x2_1a.cpp
- using routines from Cormen's book

Encryption:  E = A * M              (mod N)
Decryption:  M = Inverse(A) * E     (mod N)
							  
INPUT:  cdilot(encrypted msg), B=inverse(A)=(1 2), N=27
							                       (1 3)
							       
OUTPUT:  abcdef (encrypted msg)

*/

#include <iostream>
#include <cstring>  // strlen()
#include <cstdlib>  // exit()
using namespace std;

typedef int Matrix2x2[2][2];

int gcd(int nr1, int nr2);
int eea(int nr1, int nr2, int &x, int &y);
int inverseNr (int nr1, int N1);
void InverseMat (Matrix2x2 A, Matrix2x2 invA, int N);


////////  main  //////////////////
int main()
{
char letters[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
	
	
	char em[100];
	int i,j,n,N=27,col,rowNr=0,colNr=0;
	
	cout<<"Enter the 'encrypted' message: ";
	cin.getline(em,100);
	
	cout<<"\nem="<<em<<endl<<endl;
	
	n=strlen(em);
//   cout<<"\n n="<<n<<endl<<endl; 

	col=n;
	
	while (col%2 != 0)
	{
		col++;
	}
	
	col=col/2;
	
	int dm[2][col], sm[2][col];
	
	for (i=0; i<2; i++)
	{
		  for (j=0; j<col; j++)
		  {
		  	 dm[i][j]=26;
		 sm[i][j]=26;	   
		  }
	}  
	
	for (i=0; i<n; i++)
	{
		  for (j=0; j<27; j++)
		  {
		  	 if (em[i]==letters[j])
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
	
	int	A[2][2]; 
	int invA[2][2];
	int r, c, m=2;
	
	cout<<"\nEnter 4 nrs in matrix A: ";
	for (r=0; r<m; r++)
	{
		for (c=0; c<m; c++)
		{
			cin>>A[r][c];
			cout<<" "<<A[r][c];
		}
		cout<<endl;
	}
	
	InverseMat (A, invA, N);

	cout<<"\nThe inverse matrix is: "<<endl;
	for (r=0; r<m; r++)
	{
		for (c=0; c<m; c++)
		{   
			cout<<" "<<invA[r][c];
		}
		cout<<endl;
	}    
	
	cout<<endl<<endl;
	
	
	///////////  Matrix B=inverse(A)  ////////////////
	//int B[2][2];
	
	//cout<<"\nEnter the inverse matrix B[]: ";
	//cin>>B[0][0]>>B[0][1]>>B[1][0]>>B[1][1];
	
	///////////  Decrypt  ////////////////   
	rowNr=0;
	colNr=0;
	
	for (int m=0; m<col*2; m++)
	{
	   int matNr=0;
	   
	   for (int k=0; k<2; k++)
	   {
	   	  matNr=matNr+(invA[rowNr][k]*sm[k][colNr]);
	   }
	   
	   if (matNr>(N-1))
	   {
	   	  matNr=matNr%N;
	   }
	   
	   while (matNr<0)
	   {
	   	  matNr += N;
	   }

	   dm[rowNr][colNr] = matNr;
	   
	   colNr++;
	   
	   if (colNr==col)
	   {
		  colNr=0;
		  rowNr++;
	   }
	}
	
	cout<<"\n\ndm[]="<<endl;
	for (i=0; i<2; i++)
	{
		  for (j=0; j<col; j++)
		  {
		 cout<<dm[i][j]<<" ";	   
		  }
		  cout<<endl;
	}     
	cout<<endl;
	
	cout<<"\nThe 'decrypted' message is:"<<endl;

	for (i=0; i<col; i++)
	{
	  for (j=0; j<2; j++)
	  {
	  	cout<<letters[dm[j][i]];	   
	  }
	}     
	cout<<endl;
}


////////  gcd  ///////////
int gcd(int nr1, int nr2)
{
	int rem=1;
	
	while (rem!=0)
	{
		rem = nr1%nr2;
		nr1 = nr2;
		nr2 = rem;
	}
	return nr1;
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

void InverseMat (Matrix2x2 A, Matrix2x2 invA, int N)
{
	int i,j,gcd1, det,invDet;
	
	Matrix2x2 Adj;
	
	Adj[0][0]=A[1][1];
	Adj[0][1]=-A[0][1];
	Adj[1][0]=-A[1][0];
	Adj[1][1]=A[0][0];
	
	det = A[0][0]*A[1][1]-A[0][1]*A[1][0];
	cout<<"\nThe determinant is: "<<det<<endl;

		gcd1=gcd(det, N);
		
	if (gcd1 != 1)
	{
	  	  cout<<"ERROR2: The Inverse of matrix DOESN'T exist!"<<endl;
	}

	invDet = inverseNr (det, N);

		for (i=0; i<2; i++)
		{
			for (j=0; j<2; j++)
			{
				invA[i][j]=(invDet*Adj[i][j])%N;
			}
		}
	
		for (i=0; i<2; i++)
		{
			for (j=0; j<2; j++)
			{
				if (invA[i][j]<0)
					invA[i][j] +=N;
			}
		}		
}
