#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> Max(nums);
        vector<int> Min(nums);
        for(int i=1;i<nums.size();i++)
        {
            
                Max[i] = max(Max[i-1]*nums[i], max(Min[i-1]*nums[i], nums[i]));
                Min[i] = min(Max[i-1]*nums[i], min(Min[i-1]*nums[i], nums[i]));
            
        }
        return *max_element(Max.begin(), Max.end());
    }
};

int main()
{
    vector<int> nums = { 2, 3, -2, 4 };
    Solution s;
    cout << s.maxProduct(nums) << endl;
    return 0;
}