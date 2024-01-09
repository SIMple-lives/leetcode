#include <stdio.h>

int maxSubArray(int* nums, int numsSize) 
{
    int pre=0;
    int maxret=nums[0];
    for(int i=0;i<numsSize;i++)
    {
        pre = fmax(pre + nums[i], nums[i]);
        maxret = fmax(maxret, pre);
    }   
    return maxret;
}

int main()
{
    int numsSize = 0;
    scanf("%d", &numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++) 
    {
        scanf("%d", &nums[i]);
    }
    int max=maxSubArray(nums, numsSize);
    printf("%d\n",max);
    return 0;
}