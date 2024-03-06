#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>&nums,int start,vector<bool> &used)
    {
        result.push_back(path);
        for(int i=start;i<=nums.size();i++)
        {
            if(i>0&&nums[i-1]==nums[i]&&used[i-1]==false)//used==false 为false代表在同一层使用过该元素
            //例如num[1,1,2]有可能会出现两个[1,2].
            {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums,i+1,used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        result.clear();
        path.clear();
        vector<bool> used(nums.size( ),false);
        sort(nums.begin(), nums.end()); 
        backtracking(nums,0,used);
        return result;
    }
};
