

#include <iostream>
#include <cstring>  // strlen()
#include <cstdlib>  // exit()
using namespace std;

typedef int Matrix3x3[3][3];

int gcd(int nr1, int nr2);
int eea(int nr1, int nr2, int &x, int &y);
int inverseNr (int nr1, int N1);
void InverseMat (Matrix3x3 A, Matrix3x3 invA, int N);


////////  main  //////////////////
int main(){
char letters[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
	
	
	char em[100];
	int i,j,n,N=27,col,rowNr=0,colNr=0;
	
	cout<<"Enter the 'encrypted' message: ";
	cin.getline(em, 100);
	
	cout<<"\nem="<<em<<endl<<endl;
	
	n=strlen(em);
//   cout<<"\n n="<<n<<endl<<endl; 

	col=n;
	
	while (col%3 != 0)
	{
		col++;
	}
	
	col=col/3;
	
	int dm[3][col], sm[3][col];
	
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
		  
		  if (rowNr == 3)
		  {
		  	rowNr=0;
		  	colNr++;
		  }
	}  

	cout<<"sm[]="<<endl;
	for (i=0; i<3; i++)
	{
		  for (j=0; j<col; j++)
		  {
			cout<<sm[i][j]<<" ";	   
		  }
		  cout<<endl;
	}     

	cout<<endl;
	
	int	A[3][3]; 
	int invA[3][3];
	int r, c, m=3;
	
	cout<<"\nEnter 9 nrs in matrix A: ";
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
	//int B[3][3];

	cout<<"\nThe inverse matrix B[]: ";
	//cin>>B[0][0]>>B[0][1]>>B[1][0]>>B[1][1];
	//cin>>B[0][0]>>B[0][1]>>B[0][2] >> B[1][0]>>B[1][1]>>B[1][2] >> B[2][0]>>B[2][1]>>B[2][2]  ;
	
	///////////  Decrypt  ////////////////   
	rowNr=0;
	colNr=0;
	
	for (int m=0; m<col*3; m++)
	{
	   int matNr=0;
	   
	   for (int k=0; k<3; k++)
	   {
	   	  matNr = matNr + (invA[rowNr][k] * sm[k][colNr]);
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
	for (i=0; i<3; i++)
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
	  for (j=0; j<3; j++)
	  {
	  	cout<<letters[dm[j][i]];	   
	  }
	}     
	cout<<endl;
}


////////  gcd  ///////////
//int gcd(int nr1, int nr2)
//{
//	int rem=1;
//	
//	while (rem!=0)
//	{
//		rem = nr1%nr2;
//		nr1 = nr2;
//		nr2 = rem;
//	}
//	return nr1;
//}

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
		
		//gcd1=gcd(det, N);
		
//	if (gcd1 != 1)
//	{
//	  	  cout<<"ERROR2: The Inverse of matrix DOESN'T exist!"<<endl;
//	}

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
