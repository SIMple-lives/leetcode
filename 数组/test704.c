#include<stdio.h>

int search(int *nums, int numSize,int target)
{
    int left=0;
    int right=numSize-1;
    int mid=0;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(nums[mid]>target)
        {
            right=mid-1;
        }
        else if(nums[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    int nums[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }
    int target=0;
    scanf("%d",&target);
    int local=search(nums,n,target);
    if(local==-1)
    {
        printf("该数组没有目标元素\n");
    }
    else
    {
        printf("目标元素下标为%d\n",local);
    }
    return 0;
}