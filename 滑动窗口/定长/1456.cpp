#include <iostream>
using namespace std;

//定长滑窗套路
//入：下标为 i 的元素进入窗口，更新相关统计量。如果 i<k−1 则重复第一步。
//更新：更新答案。一般是更新最大值/最小值。
//出：下标为 i−k+1 的元素离开窗口，更新相关统计量。



class Solution {
     public:
     // 判断字符是否为元音字母
     bool isVowels(char c){
          return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
     }
     // 计算字符串s中长度为k的子串中元音字母的最大数量
     int maxVowels(string s, int k) {
          int count = 0; // 记录当前子串中元音字母的数量
          int maxCount = 0; // 记录最大元音字母数量
          for(int i = 0 ; i < s.length(); i++) {
               if(isVowels(s[i])) {
                    count++;
               }
               // 如果当前子串长度小于k，则继续循环
               if(i < k-1) {
                    continue;
               }

               // 更新最大元音字母数量
               maxCount = max(maxCount, count);
               // 如果当前子串的第一个字符是元音字母，则数量减1
               if(isVowels(s[i-k + 1])) {
                    count--;
               }
          }
          return maxCount;
     }
};

int main() {
     Solution s;
     cout << s.maxVowels("weallloveyou", 7) << endl; // 4
     return 0;
}

