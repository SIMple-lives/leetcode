#include <iostream>
#include <vector>
using namespace std;

// 滑动窗口

class Solution {
    public:
    // 定义一个函数，用于找到数组中长度为k的子数组的最大平均值
    double findMaxAverage(vector<int>& nums, int k) {
        // 定义一个变量，用于存储当前子数组的和
        int sum = 0;
        // 定义一个变量，用于存储当前子数组的最大和
        int maxSum = -__INT_MAX__;
        // 遍历数组
        for(int i = 0; i<nums.size();i++) {
            // 将当前元素加入子数组的和中
            sum += nums[i];
            // 如果当前元素不是子数组的最后一个元素，则继续遍历
            if(i < k -1) {
                continue;
            }
            // 更新子数组的最大和
            maxSum = max(maxSum, sum);
            // 将子数组的第一个元素从和中减去
            sum -= nums[i-k+1];
        }
        // 返回子数组的最大平均值
        return (double)maxSum/k;
    }
};

int main() {
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    Solution s;
    cout << s.findMaxAverage(nums, k) << endl;
    return 0;
}