#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        dp[0][0]=true;
        for(int i=1;i<=n;++i)//处理p位于前列的*
        {
            if(p[i-1]=='*')
            {
                dp[0][i]=true;
            }
            else
            {
                break;
            }
        }
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(p[j-1]=='*')//如果遇到了*,则由s去除当前的字符与p字符串是否匹配以及p去除当前的字符与s字符是否匹配.只要有一者满足即可
                {
                    dp[i][j]=dp[i][j-1]|dp[i-1][j];
                    //dp[i][j-1]      abcde  a*e
                }
                else if(p[j - 1] == '?' || s[i - 1] == p[j - 1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution v;
    string s;
    string p;
    cin >> s >> p;
    cout << v.isMatch(s, p) << endl;
    return 0;
}