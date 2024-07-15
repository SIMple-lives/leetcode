#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map <char,int> mp;
        int len = s.length();
        for(int i=0;i<len;i++)
        {
            mp[s[i]]++;
        }
        vector <pair<char,int>> v;
        for(auto it:mp)
        {
            v.push_back(it);
        }
        sort(v.begin(),v.end(),[](pair<char,int> &a,pair<char,int> &b){
           return a.second>b.second;
        });
        string ans = "";
        for(auto it:v)
        {
            for(int i=0;i<it.second;i++)
            {
                ans+=it.first;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string s1 = "tree";
    cout<<s.frequencySort(s1);
    return 0;
}