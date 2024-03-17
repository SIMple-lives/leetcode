#include <stdio.h>
#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) 
{
    int nums1count[1000]={0};//存储第一个数组
    int len=nums1Size>nums2Size?nums2Size:nums1Size;
    int *ret=(int *)calloc(len,sizeof(int));
    *returnSize=0;
    for(int i=0;i<nums1Size;i++)
    {
        nums1count[nums1[i]]++;
    }    
    for(int i=0;i<nums2Size;i++)
    {
        if(nums1count[nums2[i]]>0)
        {
            ret[(*returnSize)++]=nums2[i];
            nums1count[nums2[i]]=0;
        }
    }
    return ret;
}

int main()
{
    int num1Size=0;
    scanf("%d",&num1Size);
    int nums1[num1Size];
    for(int i=0;i<num1Size;i++)
    {
        scanf("%d",&nums1[i]);
    }
    int num2Size=0;
    scanf("%d",&num2Size);
    int nums2[num2Size];
    for(int i=0;i<num2Size;i++)
    {
        scanf("%d",&nums2[i]);
    }
    int count=0;
    int *num=intersection(nums1,num1Size,nums2,num2Size,&count);
    for(int i=0;i<count ;i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");
    free(num);
    return 0;
}