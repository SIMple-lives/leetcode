#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        int n = s.size();
        int left = 0;
        int right = 0;
        int ret = 0;
        vector<int> tmp(128,0);
        while(right<n) {
            if(tmp[s[right]]<2){
                tmp[s[right]]++;
                right++;
            }
            else {
                tmp[s[left]]--;
                left++;
            }
            ret = max (ret, right-left);
        }
        return ret;
    }
};