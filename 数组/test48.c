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
            printf("%-2d ",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}