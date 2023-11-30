#include<stdio.h>
#include<stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) 
{
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    //初始化返回结果数组ans
    int** ans = (int**)malloc(sizeof(int*) * n);
    int i;
    for(i = 0; i < n; i++) {
        ans[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    //设置每次循环的起始位置
    int startX = 0;
    int startY = 0;
    //设置二维数组的中间值，若n为奇数。需要最后在中间填入数字
    int mid = n / 2;//这个是处理最后当n为奇数的时候，对数组的最中间进行赋值.
    int loop = n / 2;//循环的圈数，中间分开所以圈数为行数除以2.
    //偏移数
    int offset = 1;//每一赋值将一行中的最后一个元素的赋值交给下一次循环.这个用来处理结尾。
    int count = 1;//用来递增进行赋值.
    while(loop) 
    {
        int i = startX;
        int j = startY;
        //模拟上侧从左到右
        for(; j < startY + n - offset; j++) 
        {
            ans[startX][j] = count++;
        }
        //模拟右侧从上到下
        for(; i < startX + n - offset; i++) 
        {
            ans[i][j] = count++;
        }
        //模拟下侧从右到左
        for(; j > startY; j--) 
        {
            ans[i][j] = count++;
        }
        //模拟左侧从下到上
        for(; i > startX; i--) 
        {
            ans[i][j] = count++;
        }
        //偏移值每次加2,因为起始位置也向后加了一位.
        offset+=2;
        //遍历起始位置每次+1
        startX++;
        startY++;
        loop--;
    }
    //若n为奇数需要单独给矩阵中间赋值
    if(n%2)
        ans[mid][mid] = count;

    return ans;
}

int main()
{
    int n=0;
    scanf("%d", &n);
    int returnColumnSizes[n][n];
    int returnSize=0;
    int **end=generateMatrix(n, &returnSize, &returnColumnSizes);   
    return  0;
}