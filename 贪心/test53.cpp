#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) 
    {
        int result = INT_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            count += nums[i];
            if(count > result)
            {
                result = count;
            }
            if(count < 0)
            count = 0;//不断更新起始位置
        }
        return result;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << s.maxSubArray(nums)<< "\n";
    return 0;
}