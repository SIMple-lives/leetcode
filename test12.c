#include <stdio.h>

#define I 1
#define IV 4
#define V 5
#define IX 9
#define X 10
#define XL 40
#define L 50
#define XC 90
#define C 100
#define CD 400
#define D 500
#define CM 900
#define M 1000

char* intToRoman(int num) 
{
    char* result = (char*)malloc(sizeof(char) * 100);
    int count = 0;

    while (num > 0) 
    {
        if (num >= M) 
        {
            result[count++] = 'M';
            num -= M;
        }
        else if (num >= CM) 
        {
            result[count++] = 'C';
            result[count++] = 'M';
            num -= CM;
        }
        else if (num >= D) 
        {
            result[count++] = 'D';
            num -= D;
        }
        else if (num >= CD) 
        {
            result[count++] = 'C';
            result[count++] = 'D';
            num -= CD;
        }
        else if (num >= C) 
        {
            result[count++] = 'C';
            num -= C;
        }
        else if (num >= XC) 
        {
            result[count++] = 'X';
            result[count++] = 'C';
            num -= XC;
        }
        else if (num >= L) 
        {
            result[count++] = 'L';
            num -= L;
        }
        else if (num >= XL) 
        {
            result[count++] = 'X';
            result[count++] = 'L';
            num -= XL;
        }
        else if (num >= X) 
        {
            result[count++] = 'X';
            num -= X;
        }
        else if (num >= IX) 
        {
            result[count++] = 'I';
            result[count++] = 'X';
            num -= IX;
        }
        else if (num >= V) 
        {
            result[count++] = 'V';
            num -= V;
        }
        else if (num >= IV) 
        {
            result[count++] = 'I';
            result[count++] = 'V';
            num -= IV;
        }
        else if (num >= I) 
        {
            result[count++] = 'I';
            num -= I;
        }
    }

    result[count] = '\0'; // Null-terminate the string
    return result;
}

int main()
{  
    int n=0;
    scanf("%d",&n);
    char *toroman =intToRoman(n);    
    printf("%s\n",toroman);
    return 0;
}