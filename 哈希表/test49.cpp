#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto&str: strs)
        {
            string key = str;
            sort(key.begin(),key.end());
            mp[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto&p: mp)
        {
            res.push_back(p.second);
        }
        return res;
    }
};

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> res = s.groupAnagrams(strs);
    for (auto& v : res) 
    {
        for (auto& s : v) 
        {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}