#include<iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int target,int k,int sum,int start)
    {
        if(sum>target)//减枝操作 当当前加和已经大于目标值，则省略后续操作
        {
            return ;
        }
        if(path.size()==k)
        {
            if(sum==target)//如果路径中的加和值等于目标值，则符合条件，将其加入结果数组
            {
                result.push_back(path);
            }
            return ;
        }
        for(int i=start;i<=9-(k-path.size())+1;i++)
        {
            sum+=i;//加入当前元素
            path.push_back(i);
            backtracking(target,k,sum,i+1);//进行递归寻找下一个元素
            sum-=i;//回溯
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backtracking(n,k,0,1);
        return result;
    }
};

int main()
{
    int n,k;
    cin>>n>>k;
    Solution s;
    vector<vector<int>> ret=s.combinationSum3(k,n);
    for(vector<vector<int>>::iterator i=ret.begin();i!=ret.end();i++)
    {
        for(vector<int>::iterator j=(*i).begin();j!=(*i).end();j++)
        {
            cout << *j << " " ;
        }
        cout << endl;
    }
    return  0;
}