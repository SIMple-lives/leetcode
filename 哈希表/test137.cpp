#include <unordered_map>
#include <iostream>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::unordered_map<int,int> map;
        for(auto i:nums)
        {
            ++map[i];
        }
        int ans=0;
        for(auto [m,n]:map)
        {
            if(n==1)
            {
                ans=m;
                break;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int singleNumber(std::vector<int>& nums) {
//         std::vector<int> ret(INT32_MAX,0);
//         std::vector<int> res(INT32_MAX,0);
//         for (int i = 0; i < nums.size(); i++) 
//         {
//             if(nums[i]<0)
//             {
//                 res[-nums[i]]++;
//             }
//             else 
//             {
//                 ret[nums[i]]++;
//             }
//         }
//         for(int i = 0; i < ret.size(); i++) 
//         {
//             if (ret[i] == 1) 
//             {
//                 return i;
//             }
//         }
//         for(int i = 0; i < res.size(); i++) 
//         {
//             if (res[i] == 1) 
//             {
//                 return -i;
//             }
//         }
//         return -1;
//     }
// };

int main()
{
    std::vector<int> nums = {2,2,1,2};
    std::cout << Solution().singleNumber(nums) << std::endl;
    return 0;
}