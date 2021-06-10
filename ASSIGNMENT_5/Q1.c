#include<stdio.h>
#include<limits.h>               //simple recursion for rod cutting problem

int max(int a, int b)
{
    return (a > b)? a : b;
}
int cutRod(int price[], int n)
{
   if (n <= 0)
     return 0;
   int Max = INT_MIN;
   for (int i = 0; i<n; i++)
         Max = max(Max, price[i] + cutRod(price, n-i-1));

   return Max;
}

int main()
{
    int arr[] = {9, 10, 17, 19, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is : %d\n", cutRod(arr, size));
    getchar();
    return 0;
}
