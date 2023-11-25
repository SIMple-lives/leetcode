#include<stdio.h>
#include<stdbool.h>

int removeDuplicates(int* nums, int numsSize) 
{
    if(numsSize==0)
    {
        return 0;
    }
    int recount=1;
    for(int i=1;i<numsSize;i++)
    {   
        int num=0;
        bool ifequal=false;
        for(int j=0;j<recount;j++)
        {
            if(nums[i]==nums[j])
            {
                num++;
            }
            if(nums[i]==nums[j] && num>1)
            {
                ifequal=true;
                break;
            }
        }
        if(ifequal==false)
        {
            nums[recount++]=nums[i];
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
    int len=removeDuplicates(nums,numsSize);
    for(int i=0;i<len;i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
    return 0;
}