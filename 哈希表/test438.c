#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(const char *s, int index, int len, int arr[]) {
    int num[26] = {0};
    for (int i = 0; i < len; i++) 
    {
        num[s[index + i] - 'a']++;
    }

    for (int i = 0; i < len; i++) 
    {
        if(num[s[index+i]-'a'])
        {
            if(arr[s[index+i]-'a'])
            {
                if(arr[s[index+i]-'a']!=num[s[index+i]-'a'])
                {
                    return 0;
                }
                else
                {
                    continue;;
                }
            }
            else
            {
                return -1;
            }
        }
    }
    return 1;
}

int* findAnagrams(const char* s, const char* p, int* returnSize) 
{
    int lenB = strlen(p);
    int lenA = strlen(s);
    *returnSize = 0;
    if(lenB>lenA)
    {
        return NULL;
    }
    int num[26] = {0};
    for (int i = 0; i < lenB; i++) {
        num[p[i] - 'a']++;
    }
    int* ret = (int*)malloc(sizeof(int) * (lenA - lenB + 1));

    for (int i = 0; i < lenA - lenB + 1; i++) {
        int mod = find(s, i, lenB, num);
        if (mod == 1) {
            ret[(*returnSize)++] = i;
        }
        else if(mod==-1)
        {
            i+lenB-1;
        }
    }

    return ret;
}

int main()
{
    char s[500];
    char p[500];
    scanf("%s",s);
    scanf("%s",p);
    int count=0;
    int *num=findAnagrams(s,p,&count);
    for(int i=0;i<count;i++)
    {
        printf("%d\n",num[i]);
    }
    free(num);
    return 0;
}