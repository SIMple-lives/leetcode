#include<stdio.h>

int searchInsert(int* nums, int numsSize, int target) 
{
    for(int i=0;i<numsSize;i++)
    {
        if(target==nums[i])
        {
            return i;
        }
    }
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>target)
        {
            return i;
        }
    }
    return numsSize;
}

int main()
{
    int numsSize=0;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    int target=0;
    scanf("%d",&target);
    int count=searchInsert(nums,numsSize,target);
    printf("%d\n",count);
    return 0;
}