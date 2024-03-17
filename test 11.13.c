#include<stdio.h>
#include<string.h>

int main()
{
    char num[10];
    for(int i=0;i<0;i++)
    {
        scanf("%c",&num[i]);
    }
    for(int i=0;i<9;i++)
    {
        printf("%c ",num[i]);
    }
    return 0;
}

/* void init(char board[54][54],char a,int end,int start)
{
    int k=0 ;
    for(int x=start,k=1;k<=2*end-1;x++,k++)
    {
        for(int y=start,k=1;k<=2*end-1;y++,k++)
        {
            board[x][y]=a;
        }
    }
}

int main()
{
    int n=0;
    int line=0;
    scanf("%d",&n);
    char a='A';
    char word[54][54]={0};
    int start=1;
    line=n;
    /* for(int i=1;i<=2*n-1;i++)
    {
        for(int j=0;j<=2*n-1;j++)
        {
            word[i][j]=a;
        }
    }
    int k=1;
    for(int i=2,k=1;k<=2*(n-1)-1;i++,k++)
    {
        for(int j=2,k=1;k<=2*(n-1)-1;j++,k++)
        {
            word[i][j]=a+1;
        }
    } */
   /*  for(int i=0;i<n;i++)
    {
        init(word,a,line,start);
        a++;
        line--;
        start++;
    } */
    /*for(int i=1;i<=2*n-1;i++)//用来进行  行数的打印。
    {
       for(int j=1;j<=2*n-1;j++)
       {
        word[i][j]=a;
       }
    }
   /*  for(int i=n;i>0;i--)//刚开始想得是转着圈进行赋值，但内部圈数与参数的关系不好找，所以考虑一行一行的输出。
    {
        for(int j=1;j<=2*n-1;j++)
        {
            word[j][count]=a;
            word[count][j]=a;
            word[2*n-1][j]=a;
            word[j][2*n-1]=a;
            a++;
            count++;
        }
    } */
    /* for(int i=1;i<=2*n-1;i++)
    {
        for(int j=1;j<=2*n-1;j++)
        {
            printf("%c",word[i][j]);
        }
        printf("\n");
    }
    return 0; */
//}
 //*/
/* int main()
{
    int nums[10000];

    return 0;
}
 */
/* int main()
{
    int a=0;
    int b=0;
    int c=0;
    scanf("%d %d %d",&a,&b,&c);
    printf("%d %d %d\n",a,b,c);
    return 0;
} */