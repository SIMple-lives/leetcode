#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    void backtracking(std::vector<int> &candidates,int target,int sum,int index)
    {
        if(sum > target)
        {
            return ;
        }
        if(sum == target)
        {
            result.push_back(path);
            return ;
        }
        for(int i=index;i<candidates.size();i++)
        {
            sum+=candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates,target,sum,i);//将当前的下标i传进去，代表可以有重复的元素.
            sum-=candidates[i];
            path.pop_back();
        }
    } 
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        backtracking(candidates,target,0,0);
        return result;
    }
};

int main()
{
    std::vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    int target = 7;
    Solution s;
    std::vector<std::vector<int>> ret=s.combinationSum(v, target);
    for(std::vector<std::vector<int>> ::iterator it=ret.begin(); it!=ret.end();it++)
    {
        for(std::vector<int> ::iterator is=(*it).begin(); is!=(*it).end();is++)
        {
            std::cout << *is << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}