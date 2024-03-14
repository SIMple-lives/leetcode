#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        int ret = 0;
        for(int left=0;left<n;++left)
        {
            int maxh=__INT_MAX__;
            for(int right=left;right<n;++right)
            {
                if(heights[right]<maxh)
                {
                    maxh=heights[right];
                }
                else
                {
                    ret = max(ret,maxh*(right-left+1));
                    break;
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> heights = {2,1,5,6,2,3};
    Solution s;
    int ret=s.largestRectangleArea(heights);
    cout << ret << endl;
    return 0;
}