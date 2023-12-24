#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int newlen=strlen(s);
    int right=newlen-1;
    int count=0;
    while (right >= 0 && s[right] == ' ') //用于去除字符串末尾的' '，类似于去除前导零.
    {
        right--;
    }
    while (s[right] != ' ' && right >= 0)//并且要保证right>=0,要确保数组不能越界.
    {
        count++;
        right--;
    }
    while (right >= 0 && s[right] != ' ') //上一个会发生栈溢出.先判断right>=0,可确保检查s[right]在数组内进行
    {
        count++;
        right--;
    }
    return count;
}

int main()
{
    char buf[1024];
    scanf("%s",buf);
    int len=lengthOfLastWord(buf);
    printf("%d\n",len);
    return 0;
}