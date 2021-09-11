#include<stdio.h>
int main()
{
   int area,num=0;
   scanf("%d",&area);
   for(int i=1;i<=area;i++)
   {
       for(int j=1;j<=area;j++)
       {
            printf("%d ",9-num);
            num++;
            num=num%9;
       }
       printf("\n");
   }
  
}