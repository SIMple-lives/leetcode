#include <vector>
using namespace std;
#include <iostream>

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m=matrix.size();//宽度
        if(m==0)
        {
            return 0;
        }
        int n = matrix[0].size();//长度
        vector<vector<int>> v(m,vector<int>(n,0));//创建一个m行，n列的数组，用来计算每一行连续的矩形块
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    v[i][j]=(j==0?0:v[i][j-1])+1;//只要是1,即为前一个加1
                }
            }
        }
        int ret = 0;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(matrix[i][j]=='0')//计算以i  j 为底的最大的矩形块
                {
                    continue;
                }
                int width = v[i][j];//宽度
                int area = width;//面积
                int height =1;//高度
                for(int k = i-1;k>=0;k--)//从i-1行知道0行遍历
                {
                    height++;
                    width=min(width,v[k][j]);
                    area=max(area,height*width);
                }
                ret=max(area,ret);
            }
        }
        return ret;
    }
};

int main()
{
    vector<vector<char>> matrix ;
    return 0;
}