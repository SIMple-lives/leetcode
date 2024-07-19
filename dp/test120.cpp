#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
            int n = triangle.size();
            std::vector<std::vector<int>> dp(n, std::vector<int>(n));
            dp[0][0] = triangle[0][0];
            for(int i=1;i<n;i++)
            {
                dp[i][0] = dp[i-1][0] + triangle[i][0];
                for(int j=1;j<i;j++)
                {
                    dp[i][j]= std::min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
                }
                dp[i][i] = dp[i-1][i-1] + triangle[i][i];
            }
            return *std::min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

int main()
{
    std::vector<std::vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution sol;
    int ret = sol.minimumTotal(triangle);
    std::cout << ret << std::endl;
    return 0;
}