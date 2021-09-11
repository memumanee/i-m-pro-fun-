#include<stdio.h>
#include<math.h>
int main(){
    int m=0,k=0;
    float n;
    printf("Enter n:");
    scanf("%f",&n);
    for(int i=0;n<= n-500*pow(1.05,k+1);i++)
    {
        m+=1;
        //k=k+1;
        if (m%10==0&&m!=0)
        {
            n=n+10;
            k=k+1;
        }
        else
        {
            n = n-(500*pow(1.05,k);
            k=k+1;
        }
        
    }
    printf("%d",m);




}


