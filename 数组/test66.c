#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize)
 {
    *returnSize = digitsSize;
    int carry = 1;

    for (int i = digitsSize - 1; i >= 0; i--)
    {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0)
    {
        (*returnSize)++;
        int* result = (int*)malloc((*returnSize) * sizeof(int));
        result[0] = carry;
        for (int i = 1; i < *returnSize; i++)
        {
            result[i] = digits[i - 1];
        }
        return result;
    }
    else
    {
        return digits;
    }
}

int main()
{
    int digitsSize = 0;
    scanf("%d", &digitsSize);
    int digits[digitsSize];
    for(int i = 0; i < digitsSize; i++)
    {
        scanf("%d", &digits[i]);
    }
    int returnSize =0;
    int *newdigits=plusOne(digits, digitsSize, &returnSize);
    for(int i = 0; i < returnSize; i++)
    {
        printf("%d\n",newdigits[i]);
    }
    free(newdigits);
    return 0;
}

/* int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    *returnSize = digitsSize+1;
    int *newnum=(int *)malloc((*returnSize) * sizeof(int));
    for(int i=0;i<digitsSize;i++)
    {
        newnum[digitsSize-i-1]=digits[i];
    }
    newnum[0]++;
    for(int i=0;i<digitsSize;i++)
    {
       if(newnum[i]>=10)
       {
            newnum[i+1]+=1;
            newnum[i]-=10;
       }
    }
    if(newnum[digitsSize]==0)
    {
        *returnSize = digitsSize;
    }
    int * returnnum=(int *)malloc((*returnSize)*sizeof(int));
    for(int i=0;i<*returnSize;i++)
    {   
        returnnum[i] = newnum[*returnSize - 1 - i];
    }
    free(newnum);
    return returnnum;
} */