#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<int> Stack;
        std::vector<int> ret(temperatures.size());
        Stack.push(0);
        for(int i=1;i<temperatures.size();i++)
        {
            if(temperatures[i]<=temperatures[Stack.top()])
            {
                Stack.push(i);
            }
            else 
            {
                while(!Stack.empty()&&temperatures[i]>temperatures[Stack.top()])
                {
                    ret[Stack.top()]=i-Stack.top();
                    Stack.pop();
                }
                Stack.push(i);
            }
        }
        return ret;
    }
};

int main()
{
    std::vector<int> temperatures={73,74,75,71,69,72,76,73};
    Solution s;
    std::vector<int> ret=s.dailyTemperatures(temperatures);
    for(int i:ret)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}