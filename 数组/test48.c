#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) 
{
    int newnum[matrixSize][matrixSize];
    for(int i = 0; i < matrixSize; i++)
    {
        for(int j = 0; j < matrixSize; j++)
        {  
            newnum[i][j] = matrix[i][j];
        }
    }
    int k=0;
    for(int i=matrixSize-1; i >= 0; i--,k++)
    {   
        for(int j = 0; j < matrixSize; j++)
        {   
            matrix[j][i]=newnum[k][j];
        }
    }
    *matrixColSize =matrixSize;
}

int main()
{
    int n=0;
    printf("\033[43;30m请输入数字:\033[0m");
    scanf("%d",&n);
    int** num = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) 
    {
        num[i] = (int*)malloc(n * sizeof(int));
    }

    int count=1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {   
            num[i][j]=count++;
        }
    }
    rotate(num,n,&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\033[42;29m%-2d\033[0m ",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}