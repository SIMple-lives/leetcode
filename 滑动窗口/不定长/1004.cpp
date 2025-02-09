#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int longestOnes(vector<int>& nums, int k) {
        // 如果nums为空，返回0
        if(nums.empty()) {
            return 0;
        }
        // 记录0的个数
        int zCount = 0;
        // 左指针
        int left = 0;
        // 返回值
        int ret = 0;
        // 右指针
        int right = 0;
        // 遍历nums
        while(right < nums.size()) {
            // 如果当前元素为0
            if(nums[right]==0) {
                // 如果0的个数小于k
                if(zCount < k) {
                    // 0的个数加1
                    zCount++;
                    right++;
                }
                else if(zCount == k) {
                    if(nums[left] == 0) {
                        zCount--;
                    }
                    left++;
                }
            }
            else {
                right++;
            }
            ret = max (right-left, ret);
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    cout << s.longestOnes(nums, 2) << endl;
    return 0;
}