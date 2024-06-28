#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int n = nums.size();
        // 
        int l = 1, r = n - 1, ans = -1;
        
        while (l <= r) 
        {
            int mid = (l + r) >> 1;
            int cnt = 0;
            //循环
            //统计小于等于mid的元素个数
            for (int i = 0; i < n; ++i) 
            {
                cnt += nums[i] <= mid;
            }
            if (cnt <= mid) 
            {
                l = mid + 1;
            } 
            else 
            {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};