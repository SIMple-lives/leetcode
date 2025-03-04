#include <bits/stdc++.h>
using namespace std;

class Solution {
    int lower_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left;
    }
    public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if(start == nums.size() || nums[start] != target) {
            return {-1 , -1};
        }
        // int end = lower_bound(nums, target + 1) - 1;
        auto end =upper_bound(nums.begin(), nums.end(), target) -1;
        int end_ = end - nums.begin() - 1;
        return {start, end_};
    }
};

class solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            auto ret = std::equal_range(nums.begin(), nums.end(), target);
    
            // 检查目标值是否存在
            if (ret.first == ret.second) {
                // 目标值不存在，返回 {-1, -1}
                return {-1, -1};
            }
    
            // 计算目标值第一次出现的索引
            int firstIndex = ret.first - nums.begin();
            // 计算目标值最后一次出现的索引
            int lastIndex = ret.second - nums.begin() - 1;
    
            // 返回包含第一次和最后一次出现位置的向量
            return {firstIndex, lastIndex};
        }
    };