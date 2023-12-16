#include <stdio.h>
#include <limits.h>

int reverse1(int x)
{
    int i=x;
    int num=0;
    while(i)
    {
        int y=i%10;
        num*=10;
        num+=y;
        i/=10;
    }
    return num;
}

int reverse2(int x){
int result = 0;
    
    while (x != 0) {
        int digit = x % 10;
        // Check for overflow before updating the result
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
            return 0;
        }
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) {
            return 0;
        }
        
        result = result * 10 + digit;
        x /= 10;
    }
    
    return result;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    int m=reverse(n);
    printf("%d\n",m);
    return 0;
}