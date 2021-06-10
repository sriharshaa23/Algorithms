import java.util.*;
class normal{
	public static int matrix(int arr[],int i,int j)
	{
		if(i>=j)
			return 0;
		int min=Integer.MAX_VALUE;
		int tempmin=0;
		for(int k=i;k<=j-1;k++)
		{
			tempmin=matrix(arr,i,k)+matrix(arr,k+1,j)+arr[i-1]*arr[j]*arr[k];
		}
		if(tempmin<min)
		{
			min=tempmin;
		}
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
		System.out.println("Minimum cost is "+matrix(arr,1,size-1));
	}
}