#include<stdio.h>
#include <string.h>
int main()
{
	char  word[50];
    int  j=0,a,e,i,o,u;
 	printf("Input Word : ", word);
	scanf("%s", word);
	//printf("length of %s = %d\n", word, strlen(word));
    //printf("1");
    while(word[j]!='\0')
    {
        if (word[j] == 'a')
        {
            a++;
        }
        if (word[j] == 'e')
        {
            e++;
        }
        if (word[j] == 'i')
        {
            i++;
        }
        if (word[j] == 'o')
        {
            o++;
        }
        if (word[j] == 'u')
        {
            u++;
        }
    }
    printf("1");
	
}

