#include<stdio.h>
void hand(int a){
    int k=0,r;
    r=a;
    for(int i=0;i<r;i++){
        a=a-1;
        k=k+a;
    }
    printf("Number of handshakes: %d\n",k);
    return ;
}
int main(){
    int n;
    printf("Enter number of people:");
    scanf("%d",&n);
    hand(n);
}