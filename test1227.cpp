#include <iostream>

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1 : 0.5;
    }
};

int main()
{
    int n;
    Solution s;
    std::cin >> n;
    std::cout << s.nthPersonGetsNthSeat(n) << std::endl;
    return 0;
}