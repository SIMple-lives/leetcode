#include <stdio.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

int maxConsecutiveChar(const char * answerKey, int k, char ch) 
{
    int n = strlen(answerKey);//计算当前的数组的长度
    int ans = 0;//
    for (int left = 0, right = 0, sum = 0; right < n; right++) 
    {
        sum += answerKey[right] != ch;
        while (sum > k) 
        {
            sum -= answerKey[left++] != ch;//减去左端不是字符的那个
        }
        ans = MAX(ans, right - left + 1);//更新ans
    }
    return ans;//返回结果
}

int maxConsecutiveAnswers(char* answerKey, int k) //思路找出当前数组最大的连续的字符数
{
    int cnt1 = maxConsecutiveChar(answerKey, k, 'T');//计算T的最长.
    int cnt2 = maxConsecutiveChar(answerKey, k, 'F');//计算F的最长.
    return MAX(cnt1, cnt2);//返回最大值.
}

int main()
{
    int n=0;
    scanf("%d",&n);
    getchar();
    char answerKey[n+1];
    for(int i=0; i<n; i++)
    {
        scanf("%c",&answerKey[i]);
        getchar();
    }
    int k=0;
    scanf("%d",&k);
    int max=maxConsecutiveAnswers(answerKey, k);
    printf("%d\n",max);
    return 0;
}