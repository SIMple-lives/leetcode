#include <stdio.h>

void bubble(int *nums)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<0-i;j++)
        {
            if(nums[j]>nums[i])
            {
                nums[j] = nums[i]^nums[j];
                nums[i] = nums[j]^nums[i];
                nums[j] = nums[i]^nums[j];
            }
        }
    }
}

int main()
{
    int nums[10]={9,8,7,6,5,4,3,2,1,0};
    bubble(nums);
    for(int i=0;i<10;i++)
    {
        printf("%d\n",nums[i]);
    }
    return 0;
}