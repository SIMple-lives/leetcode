#include <stdio.h>
#include <math.h>

int mypow(int a,int b)
{
    a %=1337;
    int ret=1;
    for(int i=0;i<b;i++)
    {
        ret *= a;
        ret %= 1337;
    }
    return ret;
}

int superPow(int a,int *b,int bSize)
{
    if(a==1)
    {
        return 1;
    }
    int sum=1;
    for(int i=0;i<bSize;i++)
    {
        sum = mypow(sum,10);
        sum *=mypow(a,b[i]);
        sum  %= 1337;
    }
    return sum;
}

int main()
{
    int a=0;
    scanf("%d",&a);
    int n=0;
    scanf("%d",&n);
    int b[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    int end=superPow(a,b,n);
    printf("%d\n",end);
    return 0;
}