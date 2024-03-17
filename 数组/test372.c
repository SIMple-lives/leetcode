#include <stdio.h>
#include <math.h>

int mypow(int a,int b)//先取模后进行计算
{
    a %=1337;//计算取模后的数字.
    int ret=1;//每一个取模后相乘，1338*1338=（1337+1)*(1337+1)%1337=1;
    for(int i=0;i<b;i++)
    {
        ret *= a;
        ret %= 1337;
    }
    return ret;//最后返回一次计算后的取模值
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
        sum = mypow(sum,10);//数组b用来表示一个整数，需要自乘10,所以需要每一次乘10。
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