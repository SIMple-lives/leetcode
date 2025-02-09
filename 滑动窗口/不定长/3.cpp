#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }
        vector<int> nums(128,0);
        int left = 0,right = 0;
        int ret = 0;
        while (right < s.size())
        {
            if(nums[s[right]] == 0) {
                nums[s[right]]++;
                right++;
            }
            else {
                nums[s[left]]--;
                left++;
            }
            ret = max(ret,right-left);
        }
        
        return ret;
    }
};

int main() {
    Solution s;
    string str = " ";
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}