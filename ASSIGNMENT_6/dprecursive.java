import java.util.*;
class dprecursive{
	public static int matrix(int arr[],int store[][],int i,int j)
	{
		if(i>=j)
			return 0;
		if(store[i][j]!=-1)
			return store[i][j];
		int min=Integer.MAX_VALUE;
		int tempmin=0;
		for(int k=i;k<=j-1;k++)
		{
			tempmin=matrix(arr,store,i,k)+matrix(arr,store,k+1,j)+arr[i-1]*arr[j]*arr[k];
		}
		if(tempmin<min)
		{
			min=tempmin;
		}
		store[i][j]=min;
		return min;
	}



	public static void main(String[] args) {
		Scanner in =new Scanner(System.in);
		int n,size;
		n=in.nextInt();
		int arr[]=new int[n];
		for(int i=0;i<n;i++)
			arr[i]=in.nextInt();
		size=arr.length;
		int store[][]=new int[size+1][size+1];
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				store[i][j]=-1;
			}
		}
		System.out.println("Minimum cost is "+matrix(arr,store,1,size-1));
	}
}