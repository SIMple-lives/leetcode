#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main()
{   
    int c=99;
    char a=c;
    char s[4];
    strcpy(s,&a);
    printf("%c\n",s[0]);
    int d=110;
    char e=d;
    strcat(s,&e);
    printf("%c",s[1]);
    return 0;
}

/* int main()
{
    char a[2];
    int c=99;
    strcpy(a,c);
    printf("%c\n",a[0]);
    return 0;
} */

/* int removeElement(int* nums, int numsSize, int val) 
{
    /* bool add=false;
    int count=numsSize;
    for(int i=0;i<count;i++)
    {
        if(add)
        {
            i--;
        }
        add=false;
        if(nums[i]==val)
        {
            for(int j=i;j<numsSize-1;j++)
            {
                nums[j]=nums[j+1];
                add=true;
            }
            count--;
        }
    }
    return count; */
    /* int count = numsSize;
    int writeIndex = 0;  // Use a separate index to write non-matching elements

    for (int i = 0; i < numsSize; i++) 
    {
        if (nums[i] != val) 
        {
            nums[writeIndex++] = nums[i];
        }
        else 
        {
            count--;
        }
    }

} */
 
/* int main()
{
    int numsSize=0;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    int val=0;
    scanf("%d",&val);
    int count=removeElement(nums,numsSize,val);
    for(int i=0;i<count;i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
    return 0;
} */