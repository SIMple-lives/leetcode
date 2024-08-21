#include <iostream>
#include <vector>

class Solution {
public:
    bool isArraySpecial(std::vector<int>& nums) {
        if(nums.empty())
        {
            return false;
        }
        int flag = nums[0]%2;
        for(int i = 1; i < nums.size(); i++) 
        {
            flag = 1 - flag;
            if(nums[i]%2 != flag)
            {
                return false;
            }
            
        }
        return true;
    }
};


int main()
{
    std::vector<int> nums = {0, 5, 3, 2, 2};
    Solution solution;
    std::cout << "Is the array special? " << (solution.isArraySpecial(nums) ? "Yes" : "No") << std::endl;
    return 0;
} 