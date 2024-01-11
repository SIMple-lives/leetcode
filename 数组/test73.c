#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) //思路，用两个数组分别来存储哪一行与那一列为0,先遍历一边数组，将需要置为0的行与列进行存储.
{
    int m = matrixSize;//行数
    int n = *matrixColSize;//列数
    int row[m], col[n];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (matrix[i][j]==0) //如果为0,则将对应的数组，置为真
            {
                row[i] = col[j] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (row[i] || col[j]) //将对应的位置进行赋值变为0.
            {
                matrix[i][j] = 0;
            }
        }
    }    
}

int main() {
    int matrixSize, matrixColSize;
    scanf("%d", &matrixSize);
    scanf("%d", &matrixColSize);
    int** matrix = (int**)malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; i++) 
    {
        matrix[i] = (int*)malloc(matrixColSize * sizeof(int));
    }
    // Input matrix elements
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixColSize; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Call the setZeroes function
    setZeroes(matrix, matrixSize, &matrixColSize);
    // Print the modified matrix
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory for the matrix
    for (int i = 0; i < matrixSize; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}