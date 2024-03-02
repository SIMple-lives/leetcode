#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    void backtracking(std::vector<int> &candidates,int target,int sum ,int index,std::vector<bool> &used)
    {
        if(sum == target) 
        {
            result.push_back(path);
            return ;
        }
        for(int i = index ; i<candidates.size()&&sum+candidates[i]<=target;i++)
        {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {//因为已经将数组排好序了，重复的数组主要原因是元素的重复，
            //当当前元素等于前一个元素的时候，used为false说明在同一树层使用过.
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i]=true;
            backtracking(candidates,target,sum,i+1,used);
            sum -= candidates[i];
            path.pop_back();
            used[i]=false;
        }
    } 
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<bool> used(candidates.size(),false);
        result.clear();
        path.clear();
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,0,used);
        return result;
    }
};

// class Solution {//这个同39一样，可以完成加和的操作，但是会有重读的数组,所以需要去重.
// public:
//     std::vector<std::vector<int>> result;
//     std::vector<int> path;
//     void backtracking(std::vector<int> &candidates,int target,int sum ,int index)
//     {
//         if(sum > target) return;
//         if(sum == target) 
//         {
//             result.push_back(path);
//             return ;
//         }
//         for(int i = index ; i<candidates.size();i++)
//         {
//             sum += candidates[i];
//             path.push_back(candidates[i]);
//             backtracking(candidates,target,sum,i+1);
//             sum -= candidates[i];
//             path.pop_back();
//         }
//     } 
//     std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
//         result.clear();
//         path.clear();
//         sort(candidates.begin(),candidates.end());
//         backtracking(candidates,target,0,0);
//         return result;
//     }
// };