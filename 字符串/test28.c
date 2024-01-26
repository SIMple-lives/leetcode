#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* int strStr(char* haystack, char* needle)
{
    if(haystack)
    {
        if(needle)
        {
            int lenH=strlen(haystack);
            int lenN=strlen(needle);
            if(lenH<lenN)
            {
                return -1;
            }
            int i=0;
            int j=0;
            while(i<lenH&&j<lenN)
            {
                if(haystack[i]==needle[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    i=i-j+1;
                    j=0;
                }
            }
            if(j==lenN)
            {
                return i-j;
            }
            return -1;
        }
        return 0;
    }
    return -1;
} */

int *getNext(const char *s) 
{
    int i = 0;
    int j = -1;
    int len = strlen(s)-1;
    int *next = (int *)malloc(sizeof(int) * len);
    next[i] = j;
    while (i < len ) 
    {
        if (j == -1 || s[i] == s[j]) 
        {
            i++;
            j++;
            next[i] = j;
        } 
        else 
        {
            j = next[j];
        }
    }
    return next;
}

int kmp(char *haystack, char *needle, int *next) 
{
    int lenH = strlen(haystack);
    int lenN = strlen(needle);
    int i = 0;
    int j = 0;
    while (i < lenH && j < lenN) 
    {
        if (needle[j] == haystack[i] || j == -1) 
        {
            i++;
            j++;
        } 
        else 
        {
            j = next[j];
        }
    }
    if (j == lenN) 
    {
        return i - j;
    }
    return -1;
}

int strStr(char *haystack, char *needle) 
{
    int *next = getNext(haystack);
    int num = kmp(haystack, needle, next);
    free(next);
    return num;
}

int main()
{
    char s[100];
    char t[100];
    scanf("%s",s);
    scanf("%s",t);
    int start=strStr(s,t);
    printf("\033[33m%d\n",start);
}