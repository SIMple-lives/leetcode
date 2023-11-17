#include<stdio.h>

/* void moveZeroes(int* nums, int numsSize) 
{
    int k=0;
    int j=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]!=0)
        {
            k=i;
        }
        else if(nums[i]==0)
        {
            j=i;
        }
        if(k<j)
        {
            nums[j]=nums[j]^nums[k];
            nums[k]=nums[j]^nums[k];
            nums[j]=nums[j]^nums[k];
        }
    }
} */

/* void moveZeroes(int* nums, int numsSize) 
{
    int k=numsSize;//0的位置
    int j=numsSize;//非0的位置.
    int tmp=0;
    for(int i=numsSize-1;i>0;i--)
    {
        if(nums[i]==0)
        {
            k=i;
        }
        else if(nums[i]!=0)
        {
            j=i;
        }
        if(j>k)
        {
           int temp=nums[k];
           for(int l=j;l>k;l--)
           {
            nums[l]=nums[l-1];

           }
        }
        k=numsSize;
        j=numsSize;
    }
} */

/* void moveZeroes(int* nums, int numsSize) //0的位置搞反了.
{
    int k=0;//0的位置
    int j=0;//非零的位置
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==0)
        {
            k=i;
        }
        else if(nums[i]!=0)
        {
            j=i;
        }
        if(j<k)
        {
            int tmp=nums[k];
            for(int l=k;l>=j;l--)
            {
                nums[l]=nums[l-1];
            }
            nums[j]=tmp;
        }
        k=0;
        j=0;
    }
} */

/* void moveZeroes(int* nums, int numsSize) //0的位置搞反了.
{
    int k=numsSize;//从后往前记录为0的值
    int j=numsSize;//从后往前记录！0值.
    for(int i=numsSize-1;i>0;i++)
    {
        if(nums[i]==0)
        {
            k=i;
        }
        else if(nums[i]!=0)
        {
            j=i;
        }
        if(j>)
    }
}
 */
/* void moveZeroes(int* nums, int numsSize) 
{
    int k=numsSize;
    for(int i=numsSize-1;i>=0;i--)
    {
        if(nums[i]==0)
        {

        }
    }
} */

/* void moveZeroes(int* nums, int numsSize) 
{
    int k=0;//0的位置
    int j=0;//非零的位置
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==0)
        {
            k=i;
        }
        else if(nums[i]!=0)
        {
            j=i;
        }
        if(j>k)
        {
            int tmp=nums[j];
            for(int l=j;l>k;l--)
            {
                nums[l]=nums[l-1];
            }
            nums[k]=tmp;
        }
        k=0;
        j=0;
    }
    int m=numsSize+1;
    {
        for(int h=0;h<numsSize;h++)
        {
            if(nums[h]==0)
            {
                m=h;
            }
        }
    }
    if(mnumsSize+1)
    {
        int left=0;
        int right=m-1;
         while(left<right)
        {
         nums[left]=nums[left]^nums[right];
         nums[right]=nums[left]^nums[right];
        nums[left]=nums[left]^nums[right];
         left++;
            right--;
        }
    }
}

int main()
{
    int n=0;
    scanf("%d",&n);
    int nums[n];
    for(int i=0;i<n;i++)
    {
     scanf("%d",&nums[i]);
    }
    moveZeroes(nums,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
    return 0;
} */

/* #include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int k = 0; // 0的位置
    int j = 0; // 非零的位置

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            k = i;
        } else {
            j = i;
        }

        if (j > k) {
            int tmp = nums[j];
            for (int l = j; l > k; l--) {
                nums[l] = nums[l - 1];
            }
            nums[k] = tmp;
        }
        k = 0;
        j = 0;
    }

    

    if (m ==1)
     {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            nums[left] = nums[left] ^ nums[right];
            nums[right] = nums[left] ^ nums[right];
            nums[left] = nums[left] ^ nums[right];
            left++;
            right--;
        }
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    moveZeroes(nums, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
 */

#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int s=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==0)
        {
            s=1;
        }
    }
    if(s==1)
    {
    int k = 0; // 0的位置
    int j = 0; // 非零的位置

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            k = i;
        } else {
            j = i;
        }

        if (j > k) {
            int tmp = nums[j];
            for (int l = j; l > k; l--) {
                nums[l] = nums[l - 1];
            }
            nums[k] = tmp;
        }
        k = 0;
        j = 0;
    }

    int m = numsSize + 1;

    for (int h = 0; h < numsSize; h++) {
        if (nums[h] == 0) {
            m = h;
        }
    }

    if (m != numsSize + 1) {
        int left = 0;
        int right = m - 1;
        while (left < right) {
            nums[left] = nums[left] ^ nums[right];
            nums[right] = nums[left] ^ nums[right];
            nums[left] = nums[left] ^ nums[right];
            left++;
            right--;
        }
    }
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    moveZeroes(nums, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
