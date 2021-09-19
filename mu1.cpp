#include <stdio.h>
#include <string.h>
char str[100];
main()
{
    while(1)
    {
        scanf("%s",str);
        strcpy(str,strlwr(str));
        if(strcmp("finished",str)==0)
            break;
        str[0]-=32;
        printf("%s ",str);
    }
}