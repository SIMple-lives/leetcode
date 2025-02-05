#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int minSwaps(vector<int>& nums) {
        // 定义变量n，用于记录数组中1的个数
        int n = 0;
        // 定义一个临时数组tmp，大小为原数组nums的两倍
        vector<int> tmp(nums.size()*2);
        // 遍历原数组nums，将nums中的元素复制到tmp中，同时记录1的个数
        // 环形断链
        for(int i = 0; i < nums.size(); i++) {
            tmp[i] = nums[i];
            tmp[i+nums.size()] = nums[i];
            if(nums[i] == 1) n++;
        }
        // 如果数组中没有1，则返回0
        if(n == 0) return 0;
        // 定义变量ret，用于记录最小交换次数
        int ret = nums.size();
        // 定义变量count，用于记录当前窗口中0的个数
        int count = 0;
        // 遍历临时数组tmp
        for(int i = 0;i < tmp.size(); i++) {
            // 如果当前元素为0，则count加1
            if(tmp[i]==0){
                count++;
            }
            // 如果当前索引小于n-1，则继续循环
            if(i<n-1) continue;
            // 更新最小交换次数
            ret = min(ret,count);
            // 如果当前窗口的第一个元素为0，则count减1
            if(tmp[i-n+1] == 0) {
                count--;
            }
        }
        // 返回最小交换次数
        return ret;
    }  
};

int main() {
    Solution s;
    vector<int> nums = {0,0,0};
    cout<<s.minSwaps(nums)<<endl;
    return 0;
}