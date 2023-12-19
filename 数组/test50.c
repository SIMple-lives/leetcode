#include <stdio.h>
#include <limits.h>

/* double myPow1(double x,int n)
{
    if(n==0)
    {
        return 1.0;
    }
    else if(n>0)
    {  
        return x*myPow(x,n-1);
    }
    else
    {   
         return 1.0 / (x * myPow(x, -(n + 1))); //处理负数的情况.
    }  
} */

double myPow2(double x,int n)
{  
    double result=1.0;
    if(n==0 || x==1)
    {   
        return 1;
    }
    if(n<0)
    { 
        x=1.0/x;
        if(n==INT_MIN)//特殊处理当n==INT_MIN时的场景，由于补码负数的限制，n为最小值的时候，-n就超出了int的范围.
        {
            result *=x;
            n++;
        }
        n*=-1;
    }
    while(n>0)
    {
        if(n%2==1)
        {
            result *=x;//如果n为奇数就乘以一次x,n/2的时候就将这一次减去了.
        }
        x*=x;
        n/=2;
    }
    return result;
}

int main()
{
    double x=0;
    scanf("%lf",&x);
    int n=0;
    scanf("%d",&n);
    double end=myPow2(x,n);
    printf("%lf\n",end);
    return 0;
}