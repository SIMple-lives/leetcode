#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // 检查字符串s1是否是字符串s2的子串
    bool checkInclusion(string s1, string s2) {
        // 如果s1的长度大于s2的长度，则s1不可能是s2的子串，返回false
        if(s1.size() > s2.size()) {
            return false;
        }
        // 定义两个长度为26的数组，用于记录s1和s2中每个字母出现的次数
        vector<int> c1(26, 0);
        vector<int> c2(26, 0);
        // 遍历s1，记录每个字母出现的次数
        for(int i = 0; i < s1.size(); i++) {
            c1[s1[i] - 'a']++;
        }
        // 遍历s2的前s1.size()个字母，记录每个字母出现的次数
        for(int i = 0; i < s1.size(); i++) {
            c2[s2[i] - 'a']++;
        }
        // 如果s1和s2的前s1.size()个字母出现的次数相同，则s1是s2的子串，返回true
        if(c1 == c2) {
            return true;
        }
        // 遍历s2的剩余字母，每次移动一个字母，更新c2中字母出现的次数
        for(int i= s1.size(); i < s2.size(); i++) {
            c2[s2[i - s1.size()] - 'a']--;
            c2[s2[i] - 'a']++;
            // 如果s1和s2的字母出现的次数相同，则s1是s2的子串，返回true
            if(c1 == c2) {
                return true;
            }
        }
        // 如果遍历完s2，s1和s2的字母出现的次数仍然不相同，则s1不是s2的子串，返回false
        return false;
    }
};

int main() {
    // 创建Solution类的对象s
    Solution s;
    // 调用checkInclusion函数，传入两个字符串参数，输出结果
    cout << s.checkInclusion("ab", "eidbaooo");
    // 返回0，表示程序正常结束
    return 0;
}