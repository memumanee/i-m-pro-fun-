#include<stdio.h>
int main(){
    int i,j,n;
    printf("Enter Size:");
    scanf("%d",&n);
    
    for(i=1;i<(n*2);i++)
    {
        for(j=1;j<(n*2);j++)
        {
            if (((i+j <= n*2)&&(i >= j))||((i+j >= n*2)&&(i <= j)))
            {
                
                printf("* ");
            }
            else
            {
                printf("  ");
            }
            
        }
        printf("\n");

    }
}