#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<std::vector<int>> result;
        if(nums1.empty() || nums2.empty() || k == 0) 
        {
            return result;
        }
        //定义优先队列的比较函数
        auto comp = [&](std::pair<int, int>& a, std::pair<int, int>& b) 
        {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        //创建优先队列，并初始化为nums1的前k个元素
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> pq(comp);
        
        //遍历nums1的前k个元素，将每个元素与nums2的第一个元素组合，放入优先队列中
        for(int i = 0; i < nums1.size() && i < k; ++i) 
        {
            pq.push({i, 0});
        }
        
        while(!pq.empty() && result.size() < k) 
        {
            auto [i, j] = pq.top();
            pq.pop();
            result.push_back({nums1[i], nums2[j]});
            //如果nums2的下一个元素存在，则将nums1的当前元素与nums2的下一个元素组合，放入优先队列中
            if(j + 1 < nums2.size()) 
            {
                pq.push({i, j + 1});
            }
        }
        return result;
    }
};

int main()
{
    std::vector<int> nums1 = { 1, 7, 11 };
    std::vector<int> nums2 = { 2, 4, 6 };
    int k = 3;
    std::vector<std::vector<int>> result = Solution().kSmallestPairs(nums1, nums2, k);
    for(auto& v : result)
    {
        for(auto& i : v)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}