#include<stdio.h>

int lengthOfLongestSubstring(char* s) 
{
    int left=0;
    int right=0;
    int max=0;
    int count=0;
    int charcount[256]={0};
    while(s[right]!='\0')
    {
        if(charcount[s[right]]==0||charcount[s[right]]>left)
        {
            charcount[s[right]]=right+1;
            max=max<right-left+1?right-left+1:max;
        }
        else
        {
            left=charcount[s[right]];
            charcount[s[right]]=right+1;
        }
    }
}

/* int lengthOfLongestSubstring(char* s) {
     int charIndex[256] = {0};  // Assuming ASCII characters

    int left = 0, right = 0, max = 0;

    while (s[right]) {
        if (charIndex[s[right]] == 0 || charIndex[s[right]] < left) {
            charIndex[s[right]] = right + 1;
            max = (right - left + 1 > max) ? right - left + 1 : max;
        } else {
            left = charIndex[s[right]];
            charIndex[s[right]] = right + 1;
        }

        right++;
    }

    return max;
} */

int main()
{
    char s[100]={0};
    scanf("%s",s);
    int count=lengthOfLongestSubstring(s);
    printf("%d\n",count);
    return 0;
}