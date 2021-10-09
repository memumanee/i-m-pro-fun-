#include<stdio.h>
#include<string.h>

int main()
{
    //struct
    struct Strinput {
    char input[20];
    };
    struct Strinput stIn[1000];
    //Input untill "."
    int i=0,a=1;
    printf("Input data string:");
    while (a==1)
    {
        scanf("%s",stIn[i].input);
        if (stIn[i].input[0]=='.')
        {
            break;
        }
        i++;
    }
    //file
    FILE *fptr;
    //open file
    fptr = fopen("data.txt", "w");
    //write
    for (int i = 0;(stIn[i].input[0]) !='.'; i++)
    {
        fprintf(fptr,"%s\n",stIn[i].input);
    }
    fprintf(fptr,".\n");

    
    
    fclose(fptr);
    
    return 0;
}