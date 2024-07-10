#include <iostream>

class Solution {
public:
    int integerReplacement(int n) {
        if(n==1)
        {
            return 0;
        }
        if(n%2==0)
        {
            return 1+integerReplacement(n/2);
        }
        else
        {
            return 2+std::min(integerReplacement(n/2),integerReplacement(n/2+1));
        }
    }
};

int main()
{
    int a;
    std::cin>>a;
    Solution s;
    std::cout<<s.integerReplacement(a);
    return 0;
}