/*  Find InverseMatrix(A)(mod N)_1a.cpp
- using routines from Cormen's book

- Given a 2x2 matrix A, find its inverse (mod N) 
 (Given A, find B such that AB=id (mod N)

Inv(3)=9(mod 26)
*/

#include <iostream>      
#include <cstdlib>  // exit()
using namespace std;

typedef int Matrix2x2[2][2];

int gcd(int nr1, int nr2);
int eea(int nr1, int nr2, int &x, int &y);
int inverseNr (int nr1, int N1);
void InverseMat (Matrix2x2 A, Matrix2x2 invA, int N);

///////////  main  /////////////
int main()
{
	int A[2][2];
	int invA[2][2];
	int r, c, n=2, N;



	cout<<"Enter N: ";
	cin>>N;
	
	cout<<"\nEnter 4 nrs in matrix A: ";
		for (r=0; r<n; r++)
		{
			for (c=0; c<n; c++)
			{
				cin>>A[r][c];
				cout<<" "<<A[r][c];
			}
			cout<<endl;
		}
	
	InverseMat (A, invA, N);


	cout<<"\nThe inverse matrix is: "<<endl;
	for (r=0; r<n; r++)
	{
		for (c=0; c<n; c++)
		{   
			cout<<" "<<invA[r][c];
		}
		cout<<endl;
	}    
	 
	cout<<endl<<endl;
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
