#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int countDays(int days, std::vector<std::vector<int>>& meetings) {
        std::sort(meetings.begin(),meetings.end());
        std::vector<std::vector<int>> ret;
        for(int i = 0;i<meetings.size();i++)
        {
            int left = meetings[i][0];
            int right = meetings[i][1];
            std::vector<int> temp;
            if(ret.size()==0 || ret.back()[1]<left)
            {
                temp.push_back(left);
                temp.push_back(right);
            }
            else
            {
                temp.push_back(ret.back()[0]);
                int num = std::max(ret.back()[1],right);
                temp.push_back(num);
                ret.pop_back();
            }
            ret.push_back(temp);
        }
        int size = ret.size()-1;
        int count = 0;
        for(int i = 1;i<=size;i++)
        {
            std::cout << ret[i][0] << " " << ret[i-1][1] << std::endl;
            count += ret[i][0]-ret[i-1][1]-1;
        }
        count += days-ret.back()[1]+ret[0][0]-1;
        return count;
    }
};

// class Solution {  超时
// public:
//     int countDays(int days, std::vector<std::vector<int>>& meetings) {
//             int count = 0;
//             std::vector<int> ret(days+1,0);
//             for(int i = 0;i<meetings.size();i++)
//             {
//                 for(int j = meetings[i][0];j<=meetings[i][1];j++)
//                 {
//                     ret[j]++;
//                 }   
//             }
//             for(int i = 1;i<=days;i++)
//             {
//                 if(ret[i]==0)
//                 {
//                     count++;
//                 }
//             }
//             return count;
//     }
// };

int main()
{
    int days = 5;
    std::vector<std::vector<int>> meetings = {{2,4},{1,3}};
    std::cout << Solution().countDays(days, meetings);
    return 0;
}