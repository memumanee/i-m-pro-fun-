#include<stdio.h>
int main(){
    int area,num=0;
   scanf("%d",&area);
   for(int i=0;i < area*area;i++)
   {
       printf("%d ",9-i%9);

       if ((i+1)%area==0)
       {
           printf("\n");
       }
    
   }

}
