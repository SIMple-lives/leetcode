#include <stdio.h>

int maxArea(int* height, int heightSize) 
{
    int length = heightSize-1;
    int max=0;
    int right=heightSize-1;
    int left=0;
    while(left<right)
    {
        int min=(height[left]<height[right])?height[left]:height[right];
        int s=min*length;
        max=max>s?max:s;
        if(height[left]>height[right])
        {
            right--;
        }
        else
        {
            left++;
        }
        length--;
    }
    return max;
}

int main()
{
    int heightSize = 0;
    scanf("%d", &heightSize);
    int height[heightSize];
    for(int i = 0; i < heightSize; i++)
    {
        scanf("%d", &height[i]);
    }
    int maxAre = maxArea(height, heightSize);
    printf("Max area: %d\n", maxAre);
    return 0;
}