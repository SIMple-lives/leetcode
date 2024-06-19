#include <vector>
#include <iostream>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();
        for(auto &it:nums)
        {
            if(it<=0)
            {
                it=n+1;
            }
        }
        for(int i=0;i<n;i++)
        {
            int num = abs(nums[i]);
            if(num<=n)
            {
                nums[num-1]=-abs(nums[num-1]);
            }
        }
        for(int i =0;i<n;i++)
        {
            if(nums[i]>0)
            {
                return i+1;
            }
        }
        return n+1;
    }
};

int main()
{
    std::vector<int> nums = {1,2,0};
    Solution s;
    std::cout << s.firstMissingPositive(nums) << std::endl; // 输出 3
    return 0; 
}