#include <iostream>
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) 
    {
        int area=0;
        if(nums.size()==1)
        {
            return true;
        }
        for(int i = 0;i<=area;i++)
        {
            area=std::max(area,i+nums[i]);
            if(area>=nums.size()-1)
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    std::vector<int> nums={2,3,1,1,4};
    std::cout<<s.canJump(nums)<<std::endl;
    Solution s1;
    return 0;
}