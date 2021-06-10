#include<stdio.h>
 
   int power(int x, unsigned int n)
   {
     if(n==0)
       return 1;
     else if(n%2 == 0)
          return power(x,n/2)*power(x,n/2);
     else
          return x*power(x,n/2)*power(x,n/2);
     }
    int main()
    {
     int x;
     unsigned int n;
     printf("Enter the value of x: ");
     scanf("%d",&x);
     printf("Enter the value of n: ");
     scanf("%d",&n);
     printf("%d",power(x,n));
     return 0;
    }