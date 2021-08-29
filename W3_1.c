#include<stdio.h>
int main(){
    int sq;
    printf("Enter number :");
    scanf("%d",&sq);
    
    for (int i = 1; i <= sq*sq; i++)
    {
        if (i<=sq || i > (sq * sq - sq))
        {
            printf("*");
        }

        if ((i-1)%sq==0 && i!=1 && i!=(sq*sq-sq+1))
        {
            printf("*");
            
        }
        else if (i % sq == 0 && i!=sq && i!=sq*sq)
        {
            printf("*");
        }
        else if (!(i<=sq || i > (sq * sq - sq)))
        {
            printf(" ");
        }
        if (i % sq == 0)
        {
            printf("\n");
        }
        
        
    }
}
