#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        int sz = nums.size();
        for(int i=0;i<sz;i++)
        {
            while(nums[i]!=nums[nums[i]-1])
            {
                int temp = nums[i];
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
            }
        }
        std::vector<int> ret;
        for(int i=0;i<sz;i++)
        {
            if(nums[i]!=i+1)
            {
                ret.push_back(nums[i]);
            }
        }
        return ret;
    }
};

int main()
{
    std::vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution s;
    std::vector<int> res = s.findDuplicates(nums);
    for (auto i : res)
    {
        std::cout << i << " ";
    }
    return 0;
}