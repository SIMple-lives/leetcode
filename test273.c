#include <stdio.h>

char* numberToWords(int num) 
{
    char *ret=(char*)malloc(sizeof(char)*500);
    if(num >= 1000000000)
    {
        
    }
}

int main()
{
    int num = 0;
    scanf("%d", &num);
    char *words=numberToWords(num);
    printf("%s\n", words);
    return 0;
}