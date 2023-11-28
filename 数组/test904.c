#include <stdio.h>
#include <stdbool.h>

int totalFruit(int* fruits, int fruitsSize) 
{
    int right = 0;//第一个遇见的值的下标，然后往后循环
    int left = 0;//用来记录一次寻找后减去第一个类型的下标.例如112223312第一次寻找后left的下标更新为2.
    int i = 0;//记录第一个类型
    int j = 0;//第二个类型.
    int count = 0;//每一次循环的可以摘到的苹果数量.
    int maxCount = 0;//记录最多可以��到的��果数量.
    while (right < fruitsSize) 
    {
        i = fruits[right];//i赋值为第一个类型
        int k = right + 1;//定义一个变量来确定第二个类型的下标.
        count = 0;//初始化count.
        while (k < fruitsSize && fruits[k] == i) 
        {
            k++;//如果当前的下标等于第二个类型的下标,则count++
        }
        if (k < fruitsSize) 
        {
            j = fruits[k];//将第二个类型赋值给第二个类型.
        }
        left=k;//记录第二个类型的下标，用于下一次循环起始循环的位置.
        while (right < fruitsSize && (fruits[right] == i || fruits[right] == j)) 
        {
            count++;//开始统计数量
            right++;//向后移动用来遍历数组
        }
        right=left;//记录第二个类型的下标，用于下一次循环起始循环的位置.
        if (count > maxCount) 
        {
            maxCount = count;//赋值.
        }
    }
    return maxCount;
   /* int right=0;
   int left=0;
   int i=0;
   int j=0;
   int end=0;
   for(;right<fruitsSize;++right)
   {
        i=fruits[right];
        int k=right+1;
        int count=0;
        while(fruits[k]==i)
        {   
            k++;
        }
        j=fruits[k];
        while(right<fruitsSize&&(fruits[right]==i||fruits[right]==j))
        {
            count++;
            if(fruits[right]!=i&&fruits[right]!=i)
            {
                break;
            }
            right++;
        }
        left=k+1;
        right=left;
        if(end<count)
        {
            end=count;
        }
   }
   return end; */
}

int main()
{
    int fruitSize=0;
    scanf("%d", &fruitSize);
    int fruits[fruitSize];
    for (int i=0;i<fruitSize;i++)
    {
        scanf("%d", &fruits[i]);
    }
    int end=totalFruit(fruits, fruitSize);
    printf("%d\n",end);
    return 0;
}