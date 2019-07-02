/*  Find InverseMatrix(A)(mod N)_3x3_1a.cpp
- using routines from Cormen's book

- Given a 3x3 matrix A, find its inverse (mod N) 
 (Given A, find B such that AB=id (mod N)
		 (1 2 3			                (2 5 6
Input: A= 4 5 6  and N=7 then B=inv(A)=  1 5 2
		  7 8 1)				         6 2 6)
*/

#include <iostream>
#include <cstdlib>  // exit()
using namespace std;

typedef int Matrix3x3[3][3];

int gcd(int nr1, int nr2);
int eea(int nr1, int nr2, int &x, int &y);
int inverseNr (int nr1, int N1);
void InverseMat (Matrix3x3 A, Matrix3x3 B, int N);

///////////  main  /////////////
int main()
{
	Matrix3x3 A, B;
	int r, c, n=3, N;

	cout<<"Enter N: ";
	cin>>N;
	
	cout<<"\nEnter 9 nrs in matrix A: ";
		for (r=0; r<n; r++)
		{
			for (c=0; c<n; c++)
			{
				cin>>A[r][c];
				cout<<" "<<A[r][c];
			}
			cout<<endl;
		}
	
	InverseMat (A, B, N);
	
	cout<<"\nThe inverse matrix is: "<<endl;
		for (r=0; r<n; r++)
		{
			for (c=0; c<n; c++)
			{
				cout<<" "<<B[r][c];
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

void InverseMat (Matrix3x3 A, Matrix3x3 B, int N)
{
	int i,j,gcd1, det,invDet;
	
	det = A[0][0]*(A[1][1]*A[2][2]-A[2][1]*A[1][2])-A[0][1]*(A[1][0]*A[2][2]-A[2][0]*A[1][2])+A[0][2]*(A[1][0]*A[2][1]-A[2][0]*A[1][1]);
	cout<<"\nThe determinant is: "<<det<<endl;

		if (det>(N-1))
		{
			det=det % N;
		}
		
		while (det < 0)
		{
			det += N;
		}
		
		gcd1=gcd(det, N);
		
	if (gcd1 != 1)
	{
	  	  cout<<"ERROR2: The Inverse of matrix DOESN'T exist!"<<endl;
	}

	invDet = inverseNr (det, N);

		B[0][0] = invDet*(A[1][1]*A[2][2]-A[2][1]*A[1][2]);
		B[0][1] = invDet*(A[0][2]*A[2][1]-A[0][1]*A[2][2]);
		B[0][2] = invDet*(A[0][1]*A[1][2]-A[0][2]*A[1][1]);
	
		B[1][0] = invDet*(A[1][2]*A[2][0]-A[1][0]*A[2][2]);
		B[1][1] = invDet*(A[0][0]*A[2][2]-A[0][2]*A[2][0]);
		B[1][2] = invDet*(A[0][2]*A[1][0]-A[0][0]*A[1][2]);	

		B[2][0] = invDet*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
		B[2][1] = invDet*(A[0][1]*A[2][0]-A[0][0]*A[2][1]);
		B[2][2] = invDet*(A[0][0]*A[1][1]-A[0][1]*A[1][0]);
		
		for (i=0; i<3; i++)
		{
			for (j=0; j<3; j++)
			{
				while (B[i][j]<0)
					   B[i][j] +=N;
					   
				while (B[i][j]>(N-1))
					   B[i][j] = B[i][j] % N;
			}
		}		
}
