#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) //双端队列.
{
    if (nums == NULL || numsSize == 0 || k <= 0)
    {
        *returnSize = 0;
        return NULL;  
    }   
    int windowSize = numsSize - k + 1;
    int *endnum = (int *)malloc(windowSize * sizeof(int)); 
    int *deque = (int *)malloc(numsSize * sizeof(int));
    int front = 0, rear = -1;   
    for (int i = 0; i < k; i++) //该循环将第一个窗口最大的元素放入deque[0]
    {       
        while (front <= rear && nums[i] > nums[deque[rear]]) 
        {
            rear--;
        }        
        deque[++rear] = i;
    }

    for (int i = k; i < numsSize; i++) 
    {       
        endnum[i - k] = nums[deque[front]];//对endnum的元素进行赋值.    
        while (front <= rear && deque[front] <= i - k) 
        {
            front++;
        }       
        while (front <= rear && nums[i] > nums[deque[rear]]) //存储较大值，将较大的值进行赋值，如果比原先的大，就将原先的覆盖掉，如果比原先的小，就将原先的保留
        {
            rear--;
        }
        deque[++rear] = i;
    }
    endnum[windowSize - 1] = nums[deque[front]];
    free(deque);
    *returnSize = windowSize;
    return endnum;
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
    int k=0;
    scanf("%d",&k);
    int returnSize=0;
    int *endnum=maxSlidingWindow(nums,numsSize,k,&returnSize);
    for(int i=0;i<returnSize;i++)
    {
        printf("%d ",endnum[i]) ;
    }
    printf("\n");
    free(endnum);
    return 0;
}

/* int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) //超出时间限制.
{
    if(nums==NULL || numsSize==0 || k<=0)
    {
        *returnSize=0;
        return NULL;
    }
    int windowSize=numsSize-k+1;
    int *endnum=(int *)malloc(windowSize*sizeof(int));
    int left=0;
    int right=0;
    int maxWindownum=nums[0];
    for(int i=1;i<k;i++)
    {
        if(maxWindownum<nums[i])
        {
            maxWindownum=nums[i];
        }
    }
    endnum[0]=maxWindownum;
    for(int i=1;i<windowSize;i++)
    {
        left++;
        right=left+k;
        maxWindownum=nums[i];
        for(int j=left;j<right;j++)
        {
            if(nums[j]>maxWindownum)
            {
                maxWindownum=nums[j];
            }
        }
        endnum[i]=maxWindownum;
    }
    *returnSize = windowSize;
    return endnum;
} */