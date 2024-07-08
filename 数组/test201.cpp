#include <iostream>

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int a=0;
        while(left<right)
        {
            left  >>=1;
            right >>=1;
            ++a;
        }
        return left << a;
    }
};

int main()
{
    int a;
    int b;
    std::cin>>a>>b;
    std::cout<<Solution().rangeBitwiseAnd(a,b);
    return 0;
}