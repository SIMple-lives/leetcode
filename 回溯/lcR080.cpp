#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> ret;
    std::vector<int> path;
    void backtracking(int n,int k,int index)
    {
        if(path.size() == k)
        {
            ret.push_back(path);
            return;
        }
        for(int i=index;i<=n;i++)
        {
            path.push_back(i);
            backtracking(n, k, i+1);
            path.pop_back();
        }
    }
    std::vector<std::vector<int>> combine(int n, int k) {
        ret.clear();
        path.clear();
        backtracking(n, k, 1);
        return ret;
    }
};

int main()
{
    int n;
    int k;
    std::cin>>n>>k;
    Solution s;
    std::vector<std::vector<int>> res = s.combine(n, k);
    for(auto i: res)
    {
        for(auto j:i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

