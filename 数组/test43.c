#include <stdio.h>
#include <string.h>

char* multiply(char* num1, char* num2) 
{
     int a[201];
    int b[201];
    int c[402];
    int len1, len2;
    len1 = strlen(num1);
    len2 = strlen(num2);
    // Initialize arrays to zero
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    for(int i = 0; i < len1; i++)
    {
        a[len1 - i] = num1[i] - '0';
    }
    for(int i = 0; i < len2; i++)
    {
        b[len2 - i] = num2[i] - '0';
    }
    int len3 = len1 + len2;
    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            c[i + j - 1] += a[i] * b[j];
            c[i + j] += c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
        }
    }
    // Find the actual length of the result
    while (len3 > 0 && c[len3] == 0)
    {
        len3--;
    }
    if (len3 == 0)
    {
        char* ret = (char*)malloc(2);
        ret[0] = '0';
        ret[1] = '\0';
        return ret;
    }
    char* ret = (char*)malloc(len3 + 1);
    for (int i = 0; i < len3; i++)
    {
        ret[i] = c[len3 - i] + '0';
    }
    ret[len3] = '\0';
    return ret;
}

int main()
{
    char num1[201];
    char num2[201];
    scanf("%s", &num1);
    scanf("%s", &num2);
    char *result=multiply(num1, num2);
    printf("%s\n", result);
    return 0;
}