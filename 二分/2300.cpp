#include <bits/stdc++.h>
using namespace std;

class Solution {
    // 在potions数组中查找能制作出success成功率的最小num
    int find(vector<int>& potions, long long success, int num) {
        // 定义左边界
        int left = 0;
        // 定义右边界
        int right = potions.size() - 1;
        // 当左边界小于等于右边界时，继续查找
        while(left <= right) {
            // 计算中间位置
            int mid = left + (right - left) / 2;
            // 计算中间位置的potions[mid]乘以num的值
            long long temp = (long long)potions[mid] * num;
            // 如果temp小于success，说明num太小，需要增大num
            if(temp < success) {
                left = mid + 1;
            }
            // 否则，说明num太大，需要减小num
            else {
                right = mid - 1;
            }
        }
        // 返回左边界
        return left;
    }
    public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // 如果spells或potions为空，则返回空向量
        if(spells.empty() || potions.empty()) {
            return {};
        }
        // 对potions进行排序
        // sort(spells.begin(),spells.end());
        sort(potions.begin(),potions.end());
        vector<int> res;
        // 遍历spells中的每个元素
        for(int i = 0; i < spells.size(); i++) {
            // 在potions中查找满足条件的元素
            int start = find(potions,success,spells[i]);
            // 将满足条件的元素个数存入res中
            res.push_back(potions.size() - start);
        }
        // 返回结果
        return res;
    }
        // vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //     if(spells.empty() || potions.empty()) {
        //         return {};
        //     }
        //     // sort(spells.begin(),spells.end());
        //     sort(potions.begin(),potions.end());
        //     int row = spells.size();
        //     int line = potions.size();
        //     vector<int> ret ;
        //     for(int i = 0 ; i < row ; i++) {
        //         int count = 0;
        //         int j = 0;
        //         for(j = 0 ; j < line ; j++) {
        //             long long end = spells[i]*potions[j];
        //             if(end>=success) {
        //                 count = line - j;
        //                 ret.push_back(count);
        //                 break;
        //             }
        //         }
        //         if(j==line) {
        //             ret.push_back(0);
        //         }
        //     }
        //     return ret;
        // }
    };