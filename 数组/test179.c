#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long cmp(int *x, int *y) 
{
    long sx = 10, sy = 10;
    while (sx <= *x) 
    {
        sx *= 10;
    }
    while (sy <= *y) 
    {
        sy *= 10;
    }
    return sx * (*y) + (*x) - sy * (*x) - (*y);
}

char *largestNumber(int *nums, int numsSize) 
{
    qsort(nums, numsSize, sizeof(int), cmp);
    if (nums[0] == 0) 
    {
        char *ret = malloc(sizeof(char) * 2);
        ret[0] = '0', ret[1] = '\0';
        return "0";
    }
    char *ret = malloc(sizeof(char) * 1000);
    char *p = ret;
    for (int i = 0; i < numsSize; i++) 
    {
        sprintf(p, "%d", nums[i]);
        p += strlen(p);
    }
    return ret;
}

int main()
{
    int numsSize =0;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    char *large=largestNumber(nums,numsSize);
    printf("%s\n",large);
    free(large);
    large=NULL;
    return 0;
}

/* int count(int n)
{
    int ret = 0;
    while(n)
    {
        ret++;
        n/=10;
    }
    return ret;
}

int flag(int a, int b)
{
    int x = 0; // a+b
    int y = 0; // b+a
    int lena = count(a);
    int lenb = count(b);
    x = a * lenb + b;
    y = b * lena + a;
    if (y>x)
    {
        return 1;
    }
    return 0;
}

int flag(int a, int b)
{
    char str1[20], str2[20];
    sprintf(str1, "%d%d", a, b);
    sprintf(str2, "%d%d", b, a);

    return strcmp(str1, str2) < 0;
}

void bubblenum(int *nums,int numsSize)
{
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=0;j<numsSize-1-i;j++)
        {
            if(flag(nums[j],nums[j+1]))
            {
                nums[j]=nums[j]^nums[j+1];
                nums[j+1]=nums[j]^nums[j+1];
                nums[j]=nums[j]^nums[j+1int count(int n)
{
    int ret = 0;
    while(n)
    {
        ret++;
        n/=10;
    }
    return ret;
}

int flag(int a, int b)
{
    int x = 0; // a+b
    int y = 0; // b+a
    int lena = count(a);
    int lenb = count(b);
    x = a * lenb + b;
    y = b * lena + a;
    if (y>x)
    {
        return 1;
    }
    return 0;
}

int flag(int a, int b)
{
    char str1[20], str2[20];
    sprintf(str1, "%d%d", a, b);
    sprintf(str2, "%d%d", b, a);

    return strcmp(str1, str2) < 0;
}

void bubblenum(int *nums,int numsSize)
{
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=0;j<numsSize-1-i;j++)
        {
            if(flag(nums[j],nums[j+1]))
            {
                nums[j]=nums[j]^nums[j+1];
                nums[j+1]=nums[j]^nums[j+1];
                nums[j]=nums[j]^nums[j+1];
            }
        }
    }
}

char* largestNumber(int* nums, int numsSize) 
{
    bubblenum(nums, numsSize);
    int endcount=0;
    for(int i=0;i<numsSize;i++)
    {
        endcount+=count(nums[i]);
    }
    char *returnnum=(char*)malloc((endcount+1)*sizeof(char));
    char buf[10];
    sprintf(buf,"%d",nums[0]);
    strcpy(returnnum,buf);
    for(int i=1;i<numsSize;i++)
    {
        sprintf(buf,"%d",nums[i]);
        strcat(returnnum,buf);   
    }
    return returnnum;
}
    bubblenum(nums, numsSize);
    int endcount=0;
    for(int i=0;i<numsSize;i++)
    {
        endcount+=count(nums[i]);
    }
    char *returnnum=(char*)malloc((endcount+1)*sizeof(char));
    char buf[10];
    sprintf(buf,"%d",nums[0]);
    strcpy(returnnum,buf);
    for(int i=1;i<numsSize;i++)
    {
        sprintf(buf,"%d",nums[i]);
        strcat(returnnum,buf);   
    }
    return returnnum;
} */