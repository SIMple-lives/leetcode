#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* bool repeatedSubstringPattern(char* s) 
{
    int len=strlen(s);//求出字符串的长度。
    for(int i=1;i<=len/2;i++)//开始寻找字串，如果长度大于一半仍然未寻找到的话，那么就不存在由字串构成
    {
        if(len%i==0)//只有长度是整数倍的时候，才有可能是字串
        {
            bool math=true;
            for(int j=i;j<len;j++)
            {
                if(s[j]!=s[j-i])
                {
                    math=false;
                    break;
                }
            }
            if(math)
            {
                return true;
            }
        }
    }
    return false;
} */

int *getNext(char *new)
{
    int len=strlen(new);
    int *next=(int *)malloc(sizeof(int)*len);
    int i=0;
    int j=-1;
    next[i]=j;
    while(i< len-1)
    {
        if(j==-1 || new[i]==new[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
    return next;
}

bool kmp(char *new,char *s,int *next)
{
    int lenN=strlen(new);
    int lenS=strlen(s);
    int i=0;
    int j=0;
    while(i<lenN&&j<lenS)
    {
        if(new[i]==s[j]||j==-1)
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
    if(j==lenS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool repeatedSubstringPattern(char* s) 
{
    int len=strlen(s);
    char *new = (char *)malloc(sizeof(char) * (len * 2 + 1));
    strcpy(new, s);
    strcat(new, s);

    for (int i = 0; i < 2 * len - 1; i++) 
    {
        new[i] = new[i + 1];
    }
    new[2 * len - 2] = '\0';
    int *next=getNext(new);
    bool end=kmp(new,s,next);
    free(next);
    free(new);
    return end;
}

int main()
{
    char s[100];
    scanf("%s",s);
    bool end=repeatedSubstringPattern(s);
    printf("\033[31m%d\n",end);   
    return 0;
}