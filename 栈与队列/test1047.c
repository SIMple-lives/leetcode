#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeDuplicates(char* s) 
{
    int len=strlen(s);
    char *stack=(char *)malloc(sizeof(char)*(len +1));
    int stacktop=0;
    int index=0;
    while(index<len)
    {
        char letter=s[index++];
        if( stacktop >0 && letter==stack[stacktop-1])
        {
            stacktop--;
        }
        else
        {
            stack[stacktop++]=letter;
        }
    } 
    stack[stacktop]='\0';
    return stack;
}

int main()
{
    char s[100];
    scanf("%s",s);
    char *ret=removeDuplicates(s);
    printf("%s\n",ret);
    free(ret);
    return 0;
}