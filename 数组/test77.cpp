#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void backtrack(int n, int k, int start, vector<int>& combination, vector<vector<int>>& combinations) 
    {
    // 组合长度达到 k，将当前组合加入结果集合中
        if (combination.size() == k) 
        {
            combinations.push_back(combination);
            return;
        }

        // 从 start 开始遍历可能的元素
        // 注意终止条件的选择，确保剩余元素个数足够构成一个组合
        for (int i = start; i <= n - (k - combination.size()) + 1; ++i) 
            {
                combination.push_back(i); // 添加当前元素到组合中
                backtrack(n, k, i + 1, combination, combinations); // 递归构造下一个元素
                combination.pop_back(); // 回溯，撤销选择的当前元素
            }
    }

    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> combinations;
        vector<int> combination;

        backtrack(n, k, 1, combination, combinations);

        return combinations;
    }
};

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    Solution s;
    vector<vector<int>> v = s.combine(n, k);
    for(vector<vector<int>>::iterator it=v.begin(); it!=v.end();it++)
    {
        for(vector<int>::iterator is= (*it).begin(); is!=(*it).end();is++)
        {
            cout << *is << " " ;
        }
        cout << endl;
    }
    return 0;
}