#include<stdio.h>
#include<stdbool.h>

bool isPerfectSquare(int num) {
    bool end=false;
    int left=1;
    int right=num;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(mid*mid<num)
        {
            left=mid+1;
        }
        else if(mid*mid>num)
        {
            right=mid-1;
        }
        else
        {
            end=true;
            break;
        }
    }
    return end;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    bool end=isPerfectSquare(n);
    printf("%d\n",end);
    return 0;
}

/* bool isPerfectSquare(int num) //超时了
{
    bool end=false;
    if(num==1)
    {
        return true;
    }
    for(long i=1;i<=num/2;i++)
    {
        if(i*i==num)
        {
            end=true;
        }
    }
    return end;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    bool end=isPerfectSquare(n);
    printf("%d\n",end);
    return 0;
} */