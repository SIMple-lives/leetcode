#include<stdio.h>
#include<stdbool.h>

bool isPowerOfTwo(int n) 
{
    if(n==0)
    {
        return false;
    }
    if(n==1)
    {
        return true;
    }
    if(n%3!=0)
    {
        return false;
    } 
    int a=n%3;
    if(a!=0)
    {
        return false;
    }
    return isPowerOfTwo(n/3);
}

int main()
{
    int n=0;
    scanf("%d",&n);
    bool end=isPowerOfTwo(n);
    printf("%d\n",end);
    return 0;
}