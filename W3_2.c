#include<stdio.h>
int main(){
    int sq;
    printf("Enter number :");
    scanf("%d",&sq);
    
    for (int i = 1; i <= sq; i++)
    {
        for(int j = 1;j <= sq; j++)
        {
            if (i == 1 || i == sq || j == 1|| j== sq)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }
}