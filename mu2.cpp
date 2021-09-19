#include <stdio.h>
#include <string.h>
char str[100],ans[10000000];
main()
{
    while(1)
    {
        scanf("%s",str);
        strcpy(str,strlwr(str));
        if(strcmp("finished",str)==0)
            break;
        str[0]-=32;
        strcat(ans,str);
        strcat(ans," ");
    }
    printf("%s",ans);
}