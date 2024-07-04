#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>


// class Solution {
// public:
//     int findKthLargest(std::vector<int>& nums, int k) {
//         std::sort(nums.begin(), nums.end());
//         return nums[nums.size() - k];
//     }
// };

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> pq;
        for (auto n : nums)
        {
            pq.push(n);
        }
        while (k--)
        {
            int n = pq.top();
            pq.pop();
            if (k == 0)
            {
                return n;
            }
        }
        return 0;
    }
};

int main()
{
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k;
    std::cin >>k;
    std::cout << Solution().findKthLargest(nums, k) << std::endl;
    return 0;
}