#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int current  = 0;
        int min = INT_MAX ;
        for(int i =0;i<cost.size();i++)
        {
            current += gas[i] - cost[i];
            min = std::min(current,min);
        }
        if(current < 0)//如果一圈的总油量小于耗费量，则无法完成一圈
        {
            return -1;    
        }
        if(min >=0)//当前每一次都大于0,则低一个加油站就可以
        {
            return 0;
        }
        for(int i = gas.size() - 1;i >= 0;i--)//从后往前倒，将min补齐。
        {
            min += gas[i] - cost[i];
            if(min >=0)
            {
                return i;
            }
        }
        return -1;
    }
};


int main()
{
    std::vector<int> gas={1,2,3,4,5};
    std::vector<int> cost={3,4,5,1,2};
    Solution s;
    std::cout << s.canCompleteCircuit(gas, cost) << std::endl;
    return 0;
}

// class Solution { //超出时间限制
// public:
//     int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
//         for(int i =0;i<gas.size();i++)
//         {
//             int ret = gas[i] - cost[i];
//             int index = (i+1) % gas.size();
//             while(ret > 0 && index != i)
//             {
//                 ret += gas[index] - cost[index];
//                 index = (index+1) % gas.size();
//             }
//             if(ret >=0 && index == i)
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };