#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int>> ret;
    std::vector<int> path;
    void backtracking(std::vector<int>&nums,std::vector<bool> &used)
    {
        if(path.size()==nums.size())
        {
            ret.push_back(path);
            return ;
        }
        for(int i =0;i<nums.size();i++)
        {
            if(used[i]==true)
            {
                continue;
            }
            used[i]=true;
            path.push_back(nums[i]);
            backtracking(nums,used);
            path.pop_back();
            used[i]=false;
        }
    }
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        ret.clear();
        path.clear();
        std::vector<bool> used(nums.size(),false);
        backtracking(nums,used);
        return ret;
    }
};

int main()
{
    std::vector<int> nums={1,2,3};
    Solution s;
    std::vector<std::vector<int>> ret = s.permute(nums);
    for(std::vector<std::vector<int>>::iterator it=ret.begin(); it!=ret.end();it++)
    {
        for(std::vector<int>::iterator is=(*it).begin(); is!=(*it).end();is++)
        {
            std::cout << *is << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}