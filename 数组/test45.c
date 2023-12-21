#include <stdio.h>

/* int jump(int* nums, int numsSize) //该方法是从每一次跳跃后的位置进行考虑的，会超出时间限制.
{
    int current = 0;//当前的位置.
    int count = 0;//跳转计数.

    while (current < numsSize - 1) 
    {
        int maxJump = nums[current];//maxjump为当前位置可以跳跃的最大值
        int nextJump = 0;//下一次跳跃的位置

        for (int i = 1; i <= maxJump && current + i < numsSize; i++) //从当前位置挨个判断看哪一个位置跳跃最远.
        {
            if (nums[current + i] + i > nums[current + nextJump] + nextJump) 
            {
                nextJump = i;
            }
        }
        current += nextJump;
        count++;
    }

    return count;
}
 */

int jump(int* nums, int numsSize) //贪心算法
{
    int count = 0;
    int current = 0;
    int maxReach = 0;
    int nextJump = 0;

    for (int i = 0; i < numsSize - 1; i++) 
    {
        maxReach = (maxReach > i + nums[i]) ? maxReach : i + nums[i];//更新每个位置跳跃的最大值.
        if (i == nextJump) //跳跃后的位置，如果到达跳跃位置，count++计数.
        {
            nextJump = maxReach;
            count++;
        }
    }
    return count;
}

int main()
{
    int numsSize=0;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0; i<numsSize; i++)
    {
        scanf("%d",&nums[i]);
    }
    int count = jump(nums, numsSize);
    printf("%d\n",count);
    return 0;
}