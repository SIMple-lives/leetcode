#include <vector>
#include <iostream>

class Solution {
public:
    int count =0;

    void backtracking(std::vector<int>& nums,int target,int index,int sum)
    {
        if(index==nums.size())
        {
            if(sum==target)
            {
                count++;
                return ;
            }
        }
        else 
        {
            backtracking(nums,target,index+1,sum+nums[index]);
            backtracking(nums,target,index+1,sum-nums[index]);
            //backtracking(nums,target,index+1,sum);
        }
    }
    int findTargetSumWays(std::vector<int>& nums, int target) {
        backtracking(nums,target,0,0);
        return count;
    }
};

int main()
{
    std::vector<int> nums = {1,1,1,1,1};
    int target = 3;
    Solution s;
    std::cout<<s.findTargetSumWays(nums,target)<<std::endl;
    return 0;
}