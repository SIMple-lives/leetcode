#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#include<limits.h>
#include<float.h>

/* char* minWindow(char* s, char* t) 
{
    if(strlen(s)<strlen(t))
    {
        return " ";
    }
    int num[strlen(s)];
    int count=0;
    for(int i=0;i<strlen(s);i++)
    {
        for(int j=0;j<strlen(t);j++)
        {
            if(s[i]==t[j])
            {
                num[i]++;
                count++;
                break;
            }
        }
    }
    if(count==0)
    {
        return " ";
    }
    int nums[count];
    int k=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(num[i]!=0)
        {
            nums[k++]=i;
        }
    }
    int grade=0;
    int small=0;
    char new[strlen(s)+1];
    strcpy(new,s);
    for(int i=0;i<k-1;i++)
    {
        for(int j=0;j<k-1-i;j++)
        {
            if(new[j]>new[j+1])
            {
                nums[j]=nums[j+1]^nums[j];
                nums[j+1]=nums[j]^nums[j+1];
                nums[j]=nums[j]^nums[j+1];
            }
        }
    }
    int lastnum[strlen(t)];
    for(int i=0;i<k;i++)
    {
        if(new[nums[i]]!=new[nums[i]+1])
        {
            lastnum[grade++]=nums[i+1];
        }
    }
} */

char* minWindow(char* s, char* t) 
{
    int map[256] = { 0 };   //用 map[] 统计字符串 t 中各字母的个数
    int current = 0;
    int minlen = strlen(s)+1;
    int start = 0;
    int sLen = strlen(s), tLen = strlen(t); //用 tLen 统计还未找到的字符串 t 中字母的个数
    for (int i = 0; i < tLen; i++) 
    {    //统计字符串 t 中各字母的个数
        map[t[i]]++;
    }
    for (int left = 0, right = 0; right < sLen; right++) 
    {
        if (map[s[right]]-- > 0) 
        {  
            tLen--; //是对应字母，则代表找到l相应的一个字母
        }
        while (tLen == 0) 
        {   
            //窗口中包含了t中的全部元素
            current = right - left + 1;
            if (current < minlen) 
            {   
                //将窗口起点进行更新，并比较最小长度
                start = left;
                minlen = current;
            }
            if (++map[s[left]] > 0) {   //统计窗口中的字母个数
                tLen++;
            }
            left++;     //左边移动1位
        }
    }
    if (minlen != sLen+1) 
    {  
        char* res = (char*)malloc(sizeof(char) * (minlen + 1));
        *res = '\0';
        strncat(res, s + start, minlen);
        return res;
    }
    return "";  
}


/* char* minWindow(char* s, char* t) 
{
    int map[256]={0};
    int start=0;
    int lens=strlen(s);
    int lent=strlen(t);
    int current=0;
    int minlen=lens+1;
    for(int i=0; i<lent; i++)
    {
        wordCount[t[i]]++;
    }
    for(int left=0,right=0;right<lens;right++)
    {
        if((wordCount[s[right]]--)>0)
        {
            lent--;
        }
        while(lent==0)
        {
            current=right-left+1;
            if(current<minlen)
            {
                minlen=right-left+1;
                start=left;
            }
            if((++wordCount[s[left]])>0)
            {
                lent++;
            }
            left++;
        }
    }
    if(minlen != (lens+1))
    {
        char *returnStr=(char*)malloc(sizeof(char)*(minlen+1));
        returnStr[minlen]='\0';
        strncat(returnStr,s+start,minlen);
        return returnStr;
    }
    return "";
} */

int main()
{
    char s[100]={0};
    char t[100]={0};
    scanf("%s",s);
    scanf("%s",t);
    char *res=minWindow(s,t);
    printf("%s\n",res);
    return 0;
}