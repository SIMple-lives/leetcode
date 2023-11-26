#include<stdio.h>

int minSubArrayLen(int target, int* nums, int numsSize) 
{
    int left = 0;
    int right = 0;
    int sum = 0;
    int min = numsSize + 1;
    for(right = 0; right < numsSize; ++right)
    {
        sum+=nums[right];
        while(sum >= target)
        {
            int sub=right-left+1;
            min=sub<min?sub:min;
            sum-=nums[left++];
        }
    }
    return min==numsSize+1?0:min;
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
    int end=minSubArrayLen(target,nums,numsSize);
    printf("%d\n",end);
    return 0;
}

/* int minSubArrayLen(int target, int* nums, int numsSize) //该方法超时了，需要通过改变循环条件来减少时间复杂度.
{
    int len=numsSize+1;
    for (int i = 0; i < numsSize; i++)
    {
        int sum = 0;
        int sum2 = 0;
        for (int j = i; j < numsSize; j++)
        {
            sum += nums[j];
            if (sum >= target)
            {
                sum2 = j - i + 1;
                if(len>sum2)
                {
                    len=sum2;
                    break;
                }
                break;
            }
        }
    }
    if(len==numsSize+1)
    {
        return 0;
    }
    return  len;
}
 */