#include<stdio.h>
int main()
{
    int n;
    printf("Enter Size:");
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
   {
      for(int j=1; j<=i; j++)
      {
          printf("* ");
      }
      for(int k=1; k<=(2*(n-i))-1; k++)
      {
          printf("  ");
      }
      for(int j=1; j<=i; j++)
      {
        
        if(j==n)
        {
          printf("  ");
        }
        else
        {
          printf("* ");
        }
      }
      printf("\n"); 
   }

   
   for(int i=1; i<=(n-1); i++)
   {
      for(int j=1; j<=(n-1)-i+1; j++)
      {
        printf("* ");
      }
      for(int k=1; k<=(2*i-1); k++)
      {
        printf("  ");
      }
      for(int j=1; j<=(n-1)-i+1; j++)
      {
        printf("* "); 
      }
      printf("\n"); 
   }

}