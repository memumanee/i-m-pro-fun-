#include<stdio.h>
int main(){
    int num[3];
    printf("num1:");
    scanf("%d",&num[0]);
    printf("num2:");
    scanf("%d",&num[1]);
    printf("(+)%d\n",num[0]+num[1]);
    printf("(-)%d\n",num[0]-num[1]);
    printf("(x)%d\n",num[0]*num[1]);
    printf("(/)%d\n",num[0]/num[1]);

}