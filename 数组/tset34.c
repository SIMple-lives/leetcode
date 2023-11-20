#include<stdio.h>
#include<stdlib.h>

/* int searchLeftborder(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int leftborder = -1;
    int mid = 0;

    while (left <= right) 
    {
        mid = (left + right) / 2;
        if (nums[mid] == target) 
        {
            leftborder = mid;
            right = mid - 1;
        }
         else if (nums[mid] > target) 
        {
            right = mid - 1;
        }
         else 
        {
            left = mid + 1;
        }
    }
    return leftborder;
}

int searchRightborder(int *nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int rightborder = -1;
    int mid = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            rightborder = mid;
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return rightborder;
}

int *binarySearch(int *nums, int numsSize, int target, int *returnSize) {
    int leftborder = searchLeftborder(nums, numsSize, target);
    int rightborder = searchRightborder(nums, numsSize, target);
    int *numlog = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    numlog[0] = leftborder;
    numlog[1] = rightborder;
    return numlog;
}

int main() {
    int numsSize = 0;
    int target = 0;
    scanf("%d", &numsSize);
    int nums[numsSize];
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &target);
    int count = 0;
    int *numlog = binarySearch(nums, numsSize, target, &count);
    for (int i = 0; i < count; i++) 
    {
        printf("%d ", numlog[i]);
    }
    printf("\n");
    free(numlog);
    return 0;
}
 */
int searchLeftborder(int *nums,int numsSize,int target)
{
    int left=0;
    int right=numsSize-1;
    int leftborder=-1;
    int mid=0;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(nums[mid]==target)
        {
            leftborder=mid;
            right=mid-1;
        }
        else if( nums[mid]>target)
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return leftborder;
}

int searchRightborder(int *nums,int numsSize,int target)
{
    int left=0;
    int right=numsSize-1;
    int rightborder=-1;
    int mid=0;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(nums[mid]==target)
        {
            rightborder=mid;
            left=mid+1;
        }
        else if(nums[mid]>target)
        {
            right=mid-1;
        }
        else 
        {
            left=mid+1;
        }
    }
    return rightborder;
}

/* int searchLeftBorder(int *nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    // 记录leftBorder没有被赋值的情况
    int leftBorder = -1;
    // 边界为[left, right]
    while (left <= right) {
        // 更新middle值，等同于middle = (left + right) / 2
        int middle = left + ((right - left) >> 1);
        // 若当前middle所指为target，将左边界设为middle，并向左继续寻找左边界
        if (nums[middle] == target) {
            leftBorder = middle;
            right = middle - 1;
        } else if (nums[middle] > target) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return leftBorder;
}
int searchRightBorder(int *nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    // 记录rightBorder没有被赋值的情况
    int rightBorder = -1;
    while (left <= right) {
        int middle = left + ((right - left) >> 1);
        // 若当前middle所指为target，将右边界设为middle，并向右继续寻找右边界
        if (nums[middle] == target) {
            rightBorder = middle;
            left = middle + 1;
        } else if (nums[middle] > target) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return rightBorder;
} */

/* int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int leftBorder = searchLeftborder(nums, numsSize, target);
    int rightBorder = searchRightborder(nums, numsSize, target);

    // 定义返回数组及数组大小
    *returnSize = 2;
    int *resNums = (int*)malloc(sizeof(int) * 2);
    resNums[0] = leftBorder;
    resNums[1] = rightBorder;
    return resNums;
}
 */
int *binarySearch(int *nums,int numsSize,int target,int *returnSize)
{
    int leftborder=searchLeftborder(nums,numsSize,target);
    int rightborder=searchRightborder(nums,numsSize,target);
    int *numlog=(int *)malloc(sizeof(int)*2);
    *returnSize=2;
    numlog[0]=leftborder;
    numlog[1]=rightborder;
    return numlog;
}

int main()
{
    int numsSize=0;
    int target=0;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    scanf("%d",&target);
    int count=0;
    int *numlog=binarySearch(nums,numsSize,target,&count);
    for(int i=0;i<count;i++)
    {
        printf("%d ",numlog[i]);
    }
    printf("\n");
    free(numlog);
    numlog=NULL;
    return 0;
}


/* int find(int *nums,int numsSize,int target)
{
    int left=0;
    int right=numsSize-1;
    int mid=0;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(nums[mid]>target)
        {
            right=mid-1;
        }
        else if(nums[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
    int *numcount=(int *)malloc(sizeof(int)*2);
    *returnSize=2;
    int mid=find(nums,numsSize,target);
    if(mid==-1)
    {
        numcount[0]=-1;
        numcount[1]=-1;    
    }
    else
    {
        int istart=mid-1;
        int iend=mid+1;
        while(nums[istart]==target)
        {
            istart--;
        }
        istart+=1;
        while(nums[iend]==target)
        {
            iend++;
        }
        iend-=1;
        numcount[0]=istart;
        numcount[1]=iend;
    }
    return numcount;
}

int main()
{
    int numsSize=0;
    int target=0;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    scanf("%d",&target);
    int count=0;
    int *numcount=searchRange(nums,numsSize,target,&count);
    for(int i=0;i,i<count;i++)
    {
        printf("%d ",numcount[i]);
    }
    printf("\n");
    free(numcount);
    numcount=NULL;
    return 0; 
} */