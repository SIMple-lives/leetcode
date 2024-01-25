#include <stdio.h>
#include <stdlib.h>

int partition(int *nums, int i, int j) 
{
    int x = nums[i];
    while (i < j) 
    {
        while (i < j && nums[j] >= x) j--;
        if (i < j) nums[i++] = nums[j];
        while (i < j && nums[i] < x) i++;
        if (i < j) nums[j--] = nums[i];
    }
    nums[i] = x;
    return i;
}

void quicksort(int *nums, int i, int j) {
    if (i < j) {
        int index = partition(nums, i, j);
        quicksort(nums, i, index - 1);
        quicksort(nums, index + 1, j);
    }
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int MAX_RESULT_SIZE = 18000;
    int **ret = (int **)malloc(sizeof(int *) * MAX_RESULT_SIZE);
    *returnSize = 0;
    if (numsSize < 4) 
    {
        return ret;
    }
    quicksort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize - 3; i++) 
    {
        if(nums[i] > target && (nums[i] >=0 || target >= 0))
        break;
        if (i > 0 && nums[i] == nums[i - 1]) 
        {
            continue;
        }

        for (int j = i + 1; j < numsSize - 2; j++) 
        {
            if (j > i + 1 && nums[j] == nums[j - 1]) 
            {
                continue;
            }
            int left = j + 1;
            int right = numsSize - 1;
            while (left < right) 
            {
                long sum =(long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum > target) 
                {
                    right--;
                }
                else if (sum < target) 
                {
                    left++;
                } 
                else 
                {
                    int *arr = (int *)malloc(sizeof(int) * 4);
                    arr[0] = nums[i];
                    arr[1] = nums[j];
                    arr[2] = nums[left];
                    arr[3] = nums[right];
                    ret[(*returnSize)++] = arr;
                    while (left < right && nums[right] == nums[right - 1]) 
                    {
                        right--;
                    }
                    while (left < right && nums[left] == nums[left + 1]) 
                    {
                        left++;
                    }

                    left++;
                    right--;
                }
            }
        }
    }

    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) 
    {
        (*returnColumnSizes)[i] = 4;
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
    int target=0;
    scanf("%d",&target);
    int returnSize=0;
    int *returnColumnSizes;
    int **ret=fourSum(nums,numsSize,target,&returnSize,&returnColumnSizes);
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