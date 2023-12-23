#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(int x) {
    char num[256];
    sprintf(num,"%d",x);
    int left=0;
    int right=strlen(num)-1;
    while(left<=right)
    {
        if(num[left]!=num[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    bool end=isPalindrome(n);
    printf("%d\n",end);
    return 0;
}