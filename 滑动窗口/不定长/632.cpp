#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // bool check(vector<vector<int>>& nums, int left , int right) {
    //     for(int i = 0; i < nums.size();i++){
    //         bool found = false;
    //         for(int j = 0;j<nums[i].size();j++) {
    //             if(nums[i][j]>=left && nums[i][j]<=right) {
    //                 found = true;
    //                 break;
    //             }
    //         }
    //         if(!found) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // // 找 nums 数组中最小的不相交子数组
    // vector<int> smallestRange(vector<vector<int>>& nums) {
    //     if(nums.size() == 0) {
    //         return {};
    //     }
    //     vector<int> tmp;
    //     int n = nums.size();
    //     for(int i = 0 ; i < n ; i++) {
    //         for(int j = 0 ; j < nums[i].size();j++) {
    //             tmp.push_back(nums[i][j]);
    //         }
    //     }
    //     sort(tmp.begin(),tmp.end());
    //     int left = 0;
    //     int right = 0;
    //     int minLen = INT_MAX;
    //     int ret_left = 0;
    //     vector<int> res;
    //     while(right < tmp.size()) {   
    //         while(left<tmp.size() && check(nums,tmp[left],tmp[right]))   {
    //             if(tmp[right]-tmp[left] < minLen) {
    //                 minLen = tmp[right]-tmp[left];
    //                 ret_left = left;
    //             }
    //             left++;
    //         }
    //         right++;
    //     }
    //     res.push_back(tmp[ret_left]);
    //     res.push_back(tmp[ret_left] + minLen);
    //     return res;
    // }
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // 如果nums为空，则返回空向量
        if(nums.empty()) {
            return {};
        }
        // 定义一个pair向量，用于存储nums中的元素及其对应的行号
        vector<pair<int,int>>  pairs;
        // 遍历nums中的每一行
        for(int i = 0 ; i < nums.size() ; i++) {
            // 遍历每一行中的每一个元素
            for(int j = 0 ; j < nums[i].size() ; j++) {
                // 将元素及其对应的行号存入pair向量中
                pairs.emplace_back(nums[i][j],i);
            }
        }
        // 对pair向量进行排序
        sort(pairs.begin(),pairs.end());
        // 初始化最小范围的最小值为pair向量的第一个元素的值
        int ans_l = pairs[0].first;
        // 初始化最小范围的最大值为pair向量的最后一个元素的值
        int ans_r = pairs.back().first;
        // 初始化空向量的大小为nums的行数
        int empty = nums.size();
        // 定义一个向量，用于存储每一行中元素的个数
        vector<int> cnt(empty);
        // 初始化左指针为0
        // 遍历pair向量
        int left = 0;
        for(auto [r,i] : pairs) {
            if(cnt[i] == 0) {
                empty--;
            }
            cnt[i]++;
            while(empty == 0) {
                auto [l,i] = pairs[left];
                if(r-l < ans_r - ans_l) {
                    ans_l = l;
                    ans_r = r;
                }
                cnt[i]--;
                if(cnt[i] == 0) {
                    empty++;
                }
                left++;
            }
        }
        return {ans_l,ans_r};
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
    vector<int> res = s.smallestRange(nums);
    for(int i = 0 ; i < res.size();i++) {
        cout << res[i] << " ";
    }
    cout <<endl;
}