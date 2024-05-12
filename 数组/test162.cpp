#include <vector>
using namespace std;
#include <algorithm>
// 方法1：暴力枚举
// 方法2：二分查找

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        auto max_it = std::max_element(nums.begin(), nums.end());
        int max_index = std::distance(nums.begin(), max_it);
        return max_index;
    }
};