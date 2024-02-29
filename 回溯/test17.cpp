#include<iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    vector<string> result;
    string path;
    string letermap[10]={"", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz" };// 9
    void backtracking(const string &digits,size_t index)
    {
        if(index==digits.size())//当下标等于输入字母的个数时，代表已经满足条件，将其加入结果集合当中
        {
            result.push_back(path);
            return ;
        }
        int dig=digits[index]-'0';//获得输入的数字
        string leters=letermap[dig];//获取相应数字对应的字母
        for(size_t i=0;i<leters.size();i++)
        {
            path.push_back(leters[i]);//将其挨个加入结果集合
            backtracking(digits,index+1);
            path.pop_back();//回溯
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        path.clear();
        result.clear();
        if(digits.size()==0)
        {
            return result;
        }
        backtracking(digits,0);
        return result;
    }
};

int main()
{
    Solution s;
    string digits;
    cin >> digits ;
    vector<string> ret=s.letterCombinations(digits);
    for(vector<string>::iterator it=ret.begin(); it!=ret.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
