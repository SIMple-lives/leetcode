#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int k=0;//用来记录数组下标的第一个位置
    int l=0;//记录第二个.
    int tmp=1;//用来退出循环.
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target&&tmp==1)
            {
                //if(nums[i]!=nums[j])
                //{
                k=i;
                l=j;
                tmp=0;
                //}   
            }
        }
    }
    *returnSize=2;
    int *newnums=(int *)malloc(2*sizeof(int));
    if(k>l)
    {
        newnums[0]=l;
        newnums[1]=k;
    }
    else
    {
        newnums[0]=k;
        newnums[1]=l;
    }
    return newnums;
}

int main()
{
    int numSize=0;
    scanf("%d",&numSize);
    int nums[numSize];
    for(int i=0;i<numSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    int target=0;
    scanf("%d",&target);
    int count=0;
    int *num=twoSum(nums,numSize,target,&count);
    for(int i=0;i<count;i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");
    free(num);
    num=NULL;
    return 0;
}