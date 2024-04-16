#include <vector>
#include <iostream>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) 
    {
        int sum =0 ;
        std::vector<int> dp(10001,0);
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1)
        {
            return false;
        }
        int target=sum/2;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=target;j>=nums[i];j--)
            {
                //1 5 11 5
                dp[j]=std::max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        if(dp[target]==target) return true;
        return false;
    }
};

int main()
{
    std::vector<int> nums={1,5,11,5};
    Solution s;
    std::cout << s.canPartition(nums)<< std::endl;
    return 0;
}