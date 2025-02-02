#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    // 获取平均值
    vector<int> getAverages(vector<int>& nums, int k) {
        // 计数器
        int count = 0;
        // 求和
        long long int sum = 0;
        // 返回结果
        vector<int> ret(nums.size(), -1);
        // 临时存储
        vector<int> tmp(nums.size(), -1);
        // 总数
        int all = 2 * k + 1;
        // 遍历数组
        for (int i = 0; i < nums.size(); i++) {
            // 累加
            sum += nums[i];
            // 如果i小于all-1，则继续
            if(i < all -1) {
                continue;
            }
            // 将平均值存入临时数组
            tmp[count++] = sum/all;
            // 减去第一个数
            sum -= nums[i - all + 1];
        }
        // 将临时数组中的值存入返回结果
        for (int i = 0; i < count; i++) {
            ret[i + k] = tmp[i];
        }
        // 返回结果
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums = {7,4,3,9,1,8,5,2,6};
    int k = 3;
    vector<int> ret = s.getAverages(nums, k);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}