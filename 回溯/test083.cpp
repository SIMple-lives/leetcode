#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    void backtracking(std::vector<int>& nums, std::vector<int> &used)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(used[i]==1)
            {
                continue;
            }
            else 
            {
                used[i] = 1;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = 0;
            }
        }
    }
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        res.clear();
        path.clear();
        std::vector<int> used(nums.size(),0 );
        backtracking(nums, used);
        return res;
    }
};

int main()
{
    std::vector<int> nums = {1, 2, 3};
    Solution s;
    std::vector<std::vector<int>> res = s.permute(nums);
    for (auto& v : res) 
    {
        for (auto& i : v) 
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}