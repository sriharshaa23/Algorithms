#include<iostream>

using namespace std;
int main()
{
	int m,n;
	
	cout<<"Enter size of array(square array) : ";
	cin>>m>>n;
	int a[m][n],b[m][n],c[m][n];

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

	for (int i = 0; i < m; ++i)
	{
		
		for (int j = 0; j < m; ++j)
		{
			c[i][j]=0;
			
			for (int k = 0; k < m; ++k)
			{
				c[i][j]= c[i][j]+ (a[i][k]*b[k][j]);
			}
		}
	}

	cout<<"Resultant matrix (c): \n";

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<" "<<c[i][j]  ;
		}

		cout<<"\n";
	}

}