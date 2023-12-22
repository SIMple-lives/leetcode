#include <stdio.h>

int lengthOfLIS(int* nums, int numsSize) 
{
    if(numsSize == 1)
    {
        return numsSize;
    }
    int dp[numsSize];//dp数组用来存储对应的元素为末尾的最长子数组.
    int maxSize = 0;
    for(int i=0;i<numsSize;i++)
    {
        dp[i]=1;//开始每一个元素组成的最长子数组元素为1.
    }
    for(int i=1;i<numsSize;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[i]>nums[j])
            {
                dp[i]= (dp[j]+1>dp[i])?dp[j]+1:dp[i];//如果当前的子数组+1比原先的大，即将子数组长度加一赋值给当前的dp[i].
                //例如：10 9 2 5 3 7 101 18  在5之前的元素没有比他本身小的，所以他就是一个自数列.
                //到5时，有一个2,加上以2为队尾形成的最大子数组。
            }
        }
        maxSize=(dp[i]>maxSize)?dp[i]:maxSize;
    }
    return maxSize;
}

int main()
{
    int numsSize =0;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    int end=lengthOfLIS(nums,numsSize);
    printf("%d\n",end);
    return 0;
}