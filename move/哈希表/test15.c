#include <stdio.h>
#include <stdlib.h>

int partition(int *nums,int i,int j)
{
    int x=nums[i];
    while(i<j)
    {
        while(i<j&&nums[j]>=x)
        {
            j--;
        }
        if(i<j)
        {
            nums[i]=nums[j];
            i++;
        }
        while(i<j&&nums[i]<x)
        {
            i++;
        }
        if(i<j)
        {
            nums[j]=nums[i];
            j--;
        }
    }
    nums[i]=x;
    return i;
}

void quicksort(int *nums,int i,int j)
{
    if(i<j)
    {
        int index=partition(nums,i,j);
        quicksort(nums,i,index-1);
        quicksort(nums,index+1,j);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
    int **ret=(int **)malloc(sizeof(int *)*18000);
    *returnSize=0;
    if(numsSize<3)
    {
        *returnSize=0;
        return ret;
    }
    quicksort(nums,0,numsSize-1);
    for(int i=0;i<numsSize-2;i++)
    {
        if(nums[i]>0)
        break;
        if(i>0&&nums[i]==nums[i-1])
        continue;
        int left=i+1;
        int right=numsSize-1;
        while(left<right)
        {
            int sum=nums[i]+nums[left]+nums[right];
            if(sum<0)
            {
                left++;
            }
            else if(sum>0)
            {
                right--;
            }
            else
            {
                int *arr=(int *)malloc(sizeof(int)*3);
                arr[0]=nums[i];
                arr[1]=nums[left];
                arr[2]=nums[right];
                ret[(*returnSize)++]=arr;
                while(left<right && nums[right]==nums[right-1])
                    right--;
                while(left<right && nums[left]==nums[left+1])
                    left++;

                left++;
                right--;
            }
        }
    }
    *returnColumnSizes=(int *)malloc(sizeof(int )*(*returnSize));
    for(int i=0;i<(*returnSize);i++)
    {
        (*returnColumnSizes)[i]=3;
    }
    return ret;
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
    int returnSize=0;
    int *returnColumnSizes;
    int **ret=threeSum(nums,numsSize,&returnSize,&returnColumnSizes);
    for(int i=0;i<returnSize;i++)
    {
        for(int j=0;j<returnColumnSizes[i];j++)
        {
            printf("%d ",ret[i][j]);
        }
        printf("\n");
    }
    free(ret);
    free(returnColumnSizes);
    return 0;
}