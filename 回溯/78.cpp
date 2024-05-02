#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    t.push_back(nums[i]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};

int main()
{

	vector<int> nums={1,2};
	Solution s;
	vector<vector<int>> ret = s.subsets(nums);
	for(auto n:ret)
	{
		for(auto m:n)
		{
			cout << m << " ";		
		}
		cout << endl;
	}
 return 0;
}
