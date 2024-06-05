#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
        {
            return {};
        }
        //将intervals按照第一个元素进行排序
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;

        //将intervals中的元素放入merged中
        for(int i =0;i<intervals.size();++i)
        {
            int L = intervals[i][0];
            int R = intervals[i][1];
            vector<int> push;

            //如果merged为空或者当前元素的第一个元素大于merged中最后一个元素的第二个元素，则将当前元素放入merged中
            if(merged.size()==0 || merged.back()[1]<L)
            {
                push.push_back(L);
                push.push_back(R);
                merged.push_back(push);
            }
            else
            {
                push.push_back(merged.back()[0]);
                int num = max(merged.back()[1],R);
                push.push_back(num);
                merged.pop_back();
            }
        }
        return merged;
    }
};