#include <climits>
#include <iostream>

class Solution {
public:
    int hammingWeight(int n) {
        int count =0;
        while(n)
        {
            if(n%2==1)
            {
                count++;
            }
            n/=2;
        }   
        return count;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::cout << Solution().hammingWeight(n) << std::endl;
    return 0;
}