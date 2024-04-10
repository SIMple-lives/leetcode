#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> ret;
    std::vector<int> path;
    void backtracking(std::vector<int> & nums,std::vector<bool> &used) 
    {
        if(path.size()==nums.size())
        {
            ret.push_back(path);
            return ;
        }
        for(size_t i=0;i<nums.size();i++)
        {
            //used[i-1]==true;则证明同一个树枝上同一节点被访问过
            //used[i-1]==false;则证明同一层使用过了
            if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false)
            {
                continue;
            }
            if(used[i]==false)
            {
                used[i]=true;
                path.push_back(nums[i]);
                backtracking(nums,used);
                used[i]=false;
                path.pop_back();
            }
        }
    }
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        ret.clear();
        path.clear();
        std::sort(nums.begin(), nums.end());
        std::vector<bool> used(nums.size(), false);
        backtracking(nums,used);
        return ret;
    }
};

int main()
{
    std::vector<int> v={1,1,2};
    Solution s;
    std::vector<std::vector<int>> ret = s.permuteUnique(v);
    for(auto &i : ret)
    {
        for(auto &j :i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
