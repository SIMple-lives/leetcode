
#include <stdio.h>

int IsAutomorphic(int x);
void FindAutomorphic(int lower, int upper);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    FindAutomorphic(a, b);
    return 0;
}


/* 请在这里填写答案 */
int IsAutomorphic(int x)
{
    if(x==0||x==1)
    {
        return 1;
    }
    int s=x*x;
    int t=x;
    int size;
    while(t)
    {
        size++;
        t/=10;
    }
    for(int i=0;i<size;i++)
    {
        if(s%10!=x%10)
        {
            return 0;
        }
        s/=10;
        x/=10;
    }
    return 1;
}

void FindAutomorphic(int lower,int upper)
{
    static int count =0;
    if(lower>upper)
    {
        return;
    }
    if(IsAutomorphic(lower))
    {
        printf("%d ",lower);
        count ++;
    }
    FindAutomorphic(lower+1,upper);
    if(count==0)
    {
        printf("None");
        count =1;
        return;
    }
    return ;
}