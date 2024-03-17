#include<stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    int recount=1;
    int new=numsSize;
    for(int i=1;i<numsSize;i++)
    {
        for(int j=0;j<=recount-1;j++)
        {
            if(nums[i]==nums[j])
            {
                new--;
                break;
            }
            else
            {
                nums[recount++]=nums[i];//这里的思路有点问题，这里会使得recount不断自增赋值超过原数组长，存在内存问题.
            }
        }
    }
    return recount;
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
    int count=removeDuplicates(nums,numsSize);
    for(int i=0;i<count;i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
    return 0;
}

/* int removeDuplicates(int* nums, int numsSize)//这里用到了bool来直观的进行判断，如果不相等，则进行覆盖，相等则退出循环.
{
    if(numsSize==0)
    {
        return 0;
    }
    int recount=1;
    for(int i=1;i<numsSize;i++)
    {
        bool num=false;
        for(int j=0;j<recount;j++)
        {
            if(nums[i]==nums[j])
            {
                num=true;
                break;
            }
        }
        if(num==false)
        {
            nums[recount++]=nums[i];
        }
    }
    return recount;
} */