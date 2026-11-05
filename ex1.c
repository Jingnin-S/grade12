#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char *str;
    if((str=(char*)malloc(10))==NULL)
    {
        printf("not enough space\n");
        exit(1);
    }
    strcpy(str,"hello");
    printf("string is %s",str);
    free(str);
    return 0;
}


