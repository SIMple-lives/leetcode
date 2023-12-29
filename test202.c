#include <stdio.h>
#include <stdbool.h>


int getnum(int n)
{
    int ret=0;
    while(n)
    {
        ret+=(n%10)*(n%10);
        n/=10;        
    }
    return ret;
}

 bool isHappy(int n) {//不用递归在，本函数内部用一个数组进行操作.
    int sum=getnum(n);
    int hash[1000]={0};
    while(sum!=1)
    {
        if(hash[sum]==1)
        {
            return false;
        }
        else
        {
            hash[sum]++;
        }
        sum=getnum(hash[sum]);
    }
    return true;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    bool end=isHappy(n);
    printf("%d\n",end);
    return 0;
}

/* bool isHappyRecursive(int n,int *ifexist)//测试用例有点少
{
    if(n==1)
    {
        return true;
    }
    if(ifexist[n])
    {
        return false;
    }
    ifexist[n] = 1;
    int sum=0;
    while(n)
    {
        int x=n%10;
        int y=x*x;
        sum+=y;
        n/=10;
    }
    return isHappyRecursive(sum,ifexist);
}

bool isHappy(int n) {
    int ifexist[1000]={0};//要对该数组进行初始化，有可能产生ub行为，从而导致后面进行判断的时候会出现错误
    return isHappyRecursive(n,ifexist);
}
 */