#include<iostream>
#include<cmath>
using namespace std;

int ** allocate(int m)
{
	int **arr=new int*[m];
	for (int i = 0; i < m; ++i)
	{
		arr[i]=new int[m];
	}
	return arr;

	/* int **matrix = (int **)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        matrix[i] = (int*)calloc(row, sizeof(int));
    }
    return matrix;*/
}

int **matrixAdd(int** a,int** b,int n)
{
	int **arr=new int*[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i]=new int[n];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			arr[i][j]=a[i][j]+b[i][j];
		}
	}
    printf("10\n");
	return arr;
}

int **SquareMatrixMultiplicationRecursive(int **A,int **B,int n)
{
	
    int ** C=allocate(n);
    if(n==1)
    {
      	C[0][0]=A[0][0]*B[0][0];

    }
    
    else{
    	int row=n/2;
        int** a11=allocate(row);
        int** a12=allocate(row);
        int** a21=allocate(row);
        int** a22=allocate(row);
        int** b11=allocate(row);
        int** b21=allocate(row);
        int** b12=allocate(row); 
        int** b22=allocate(row); 
      
       

        for(int i=0;i<row;i++)
        {
        	for (int j = 0; j< row; ++j)
        	{
        		a11[i][j]=A[i][j];
        		a12[i][j]=A[i][j+row];
        		a21[i][j]=A[i+row][j];
        		a22[i][j]=A[i+row][j+row];
        		b11[i][j]=B[i][j];
        		b12[i][j]=B[i][j+row];
        		b21[i][j]=B[i+row][j];
        		b22[i][j]=B[i+row][j+row];

        	}
        }

        
        int **c11=matrixAdd(SquareMatrixMultiplicationRecursive(a11,b11,row),
                SquareMatrixMultiplicationRecursive(a12,b21,row),row);
        int **c12=matrixAdd(SquareMatrixMultiplicationRecursive(a11,b12,row),
                 SquareMatrixMultiplicationRecursive(a12,b22,row),row);          
        int **c21=matrixAdd(SquareMatrixMultiplicationRecursive(a21,b11,row),
                 SquareMatrixMultiplicationRecursive(a22,b21,row),row);
       int **c22=matrixAdd(SquareMatrixMultiplicationRecursive(a21,b12,row),
                SquareMatrixMultiplicationRecursive(a22,b22,row),row); 

     

         for (int i = 0; i < row; ++i)
        {
        	for (int j = 0; j < row; ++j)
        	{
        		C[i][j]=c11[i][j];
        		C[i][row+j]=c12[i][j];
        		C[i+row][j]=c21[i][j];
        		C[i+row][j+row]=c22[j][j];
        		
        	}
        	printf("\n");
        } 

      

        
    }

   
   
   return C;

}

int main()
{
	int m,n,k;
	
	cout<<"Enter k(square array) : ";
	cin>>k;
    m=pow(2,k);
	int **a=allocate(m);
	int **b=allocate(m);
	/*a=new int*[m];
	for (int i = 0; i < m; ++i)
	{
		a[i]=new int[m];
	}

	b=new int*[m];
	for (int i = 0; i < m; ++i)
	{
		b[i]=new int[m];
	}*/

	

    cout<<"Enter array elements of first array (a): ";
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
            cin>>a[i][j];
		}
	}

	cout<<"Enter array elements of second array (b): ";
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
            cin>>b[i][j];
	    }
	}
    cout<<"A\n";
    for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<" "<<a[i][j]  ;
		}

		cout<<"\n";
	}

    cout<<"B\n";
    for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<" "<<b[i][j] ;
		}

		cout<<"\n";
	}

	int** c=SquareMatrixMultiplicationRecursive(a,b,m);
    

    cout<<"RESULT\n";
    for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<" "<<c[i][j] ;
		}

		cout<<"\n";
	}

}