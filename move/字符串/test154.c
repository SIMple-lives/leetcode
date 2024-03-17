#include <stdio.h>
#include <string.h>

//去除多余的空格
void removeExtra(char *s)
{
    int start=0;
    int end=strlen(s)-1;
    while(s[start]==' ')
    {
        start++;
    }
    while(s[end]==' ')
    {   
        end--;
    }
    int next=0;//进行覆盖的方式进行赋值
    for(int i=start;i<=end;i++)
    {
        if(s[i]==' '&&s[i+1]==' ')
        {
            continue;
        }
        s[next]=s[i];
        next++;
    }
    s[next]='\0';
}

void reverse(char *s,int i,int j)
{
    while(i<=j)//翻转
    {
        int tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
        i++;
        j--;
    }
}

char* reverseWords(char* s)//分为3步
{
    //删除多余的空格
    removeExtra(s);
    //将整个句子翻转
    reverse(s,0,strlen(s)-1);
    int next=0;
    //翻转每一个单词
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]==' '||s[i]=='\0')
        {
            reverse(s,next,i-1);
            next=i+1;
        }
    }
    return s;
}