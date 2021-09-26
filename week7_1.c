#include<stdio.h>
void hand(int a)
{
    int h;
    h=((a-1)*a)/2;
    printf("Number of handshakes: %d\n",h);
    return ;
}
int main(){
    int n;
    printf("Enter number of people:");
    scanf("%d",&n);
    hand(n);
}