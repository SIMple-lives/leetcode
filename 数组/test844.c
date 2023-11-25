#include<stdio.h>
#include<stdbool.h>
#include<string.h>

char* build(char* str) 
{
    int n = strlen(str), len = 0;
    char* ret = malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) 
    {
        if (str[i] != '#') 
        {
            ret[len++] = str[i];
        } 
        else if (len > 0) 
        {
            len--;
        }
    }
    ret[len] = '\0';
    return ret;
}

bool backspaceCompare(char* S, char* T) 
{
    return strcmp(build(S), build(T)) == 0;
}


/* bool backspaceCompare(char* s, char* t) //覆盖法可以实现，但无法解决退格符连在一块的问题.可以考虑从后面往前面进行读数字.
{
    int leni=strlen(s)-1;
    int lenj=strlen(t)-1;
    int skipS=0;//用来存储s字符串中待处理的退格符
    int skipT=0;//用来存储t字符窜中待处理的退格符
    while(leni>=0||lenj>=0)
    {
        while(leni>=0&&(skipS>0||s[leni]=='#'))
        {
            if(s[leni]=='#')
            {
                skipS++;
            }
            else
            {
                skipS--;
            }
            leni--;
        }
        while(lenj>=0&&(skipT>0||t[lenj]=='#'))
        {
            if(t[lenj]=='#')
            {
                skipT++;
            }
            else
            {
                skipT--;
            }
            lenj--;
        }
        if(leni>=0&&lenj>=0&&s[leni]!=t[lenj])
        {
            return false;
        }
        if(leni<0||lenj<0)
        {
            return false;
        }
        leni--;
        lenj--;
    }
    if(leni>=0||lenj>=0)
    {
        return true;
    }
    return leni<0&&lenj<0;
} */

int main()
{   
    char s[201]={0};
    char t[201]={0};
    scanf("%s %s",s,t);
    bool end=backspaceCompare(s,t);
    printf("%d\n",end);
    return 0;
}

/* bool backspaceCompare(char* s, char* t) //覆盖法可以实现，但无法解决退格符连在一块的问题.可以考虑从后面往前面进行读数字.
{
    int len1=strlen(s);
    int len2=strlen(t);
    for(int i=0;i<len1;i++)
    {
        if(s[i]=='#')
        {
            s[i-1]=s[i+1];
            for(int j=i+1;j<len1-1;j++)
            {
                s[j]=s[j+1];
            }
        }
    }
    for(int i=0;i<len1;i++)
    {
        if(t[i]=='#')
        {
            t[i-1]=t[i+1];
            for(int j=i+1;j<len1-1;j++)
            {
                t[j]=t[j+1];
            }
        }
    }
    int equal=strcmp(s,t);
    if(equal!=0)
    return false;
    else
    return true;
} */

/* bool backspaceCompare(char* s, char* t) //虽然\b代表退格符，但实际并不能很好的得到我们想要的结果.还是应该采取覆盖的方法。
{
    int len1=strlen(s);
    int len2=strlen(t);
    for(int i=0;i<len1;i++)
    {
        if(s[i]=='#')
        {
            s[i]='\b';
        }
    }
    for(int i=0;i<len2;i++)
    {
        if(t[i]=='#')
        {
            t[i-1]='\b';
        }
    }
    int ifequal=strcmp(s,t);
    if(ifequal==0)
    {
        return true;
    }
    return false;
}
 */

/* bool backspaceCompare(char* s, char* t) 
{
    int len1=strlen(s);
    int len2=strlen(t);
    for(int i=0;i<len1;i++)
    {
        if(s[i]=='#'&&i-1>=0)
        {
            s[i-1]='#';
        }
    }
    for(int i=0;i<len2;i++)
    {
        if(t[i]=='#'&&i-1>=0)
        {
            t[i-1]='#';
        }
    }
    int ifequal=strcmp(s,t);
    if(ifequal==0)
    {
        return true;
    }
    return false;
}  */