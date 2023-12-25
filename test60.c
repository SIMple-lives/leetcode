#include <stdio.h>

int climbStairs(int n) 
{
    int a=0;
    int b=0;
    int c=1;
    for(int i=1;i<=n;++i)
    {
        a=b;
        b=c;
        c=a+b;
    }   
    return c;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    int count = 0;
    count=climbStairs(n);
    printf("%d\n",count);
    return 0;
}