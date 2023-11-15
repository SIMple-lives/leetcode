#include<stdio.h>

void initboard(int num[][31],int n)
{
    for(int i=1;i<=n;i++)
    {
        num[0][0]=1;
        for(int j=1;j<=i;j++)
        {
            num[i][j]=num[i-1][j]+num[i-1][j-1];
        }
    }
}

int main()
{
    int num[31][31]={0};
    int n=0;
    scanf("%d",&n);
    initboard(num,n);
    printf("[");
    for(int i=1;i<=n;i++)
    {
        printf("[");
        for(int j=1;j<=i;j++)
        {
            if(j!=i)
            {
            printf("%d,",num[i][j]);
            }
            else if(j==i)
            {
                printf("%d",num[i][j]);
            }
        }
        if(i!=n)
            {
                 printf("],");
            }
            else
            {
                printf("]");
            }
    }
    printf("]\n");
    return 0;
}