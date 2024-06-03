#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n-1);
        stack<int> S;
        for(int i = 0;i<2*n-1;i++)
        {
           while (!S.empty() && nums[S.top()] < nums[i % n]) 
           {
                ret[S.top()] = nums[i % n];
                S.pop();
            }
            S.push(i % n);
        }
        return ret;
    }
};