#include<stdio.h>

int mySqrt(int x) {
    for(int i=1;i<=x/2;i++)
    {
        if((i*i)<=x&&((i+1)*(i+1)>x))
        {
            return i;
        }
    }
    return x;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    int sqrtnum=mySqrt(n);
    printf("%d\n",sqrtnum);
    return 0;
}

/* int my_sqrt(int n)//会超出int的范围
{
    for(int i=1;i<n;i++)
    {
        int add=i*i;
        int add_next=(i+1)*(i+1);
        if(add<=n&&add_next>n)
        {
            return i;
        }
    }
    return n;
} */

/* int main()
{
    int n=0;
    scanf("%d",&n);
    int num=my_sqrt(n);
    printf("%d\n",num);
    return 0;

} */