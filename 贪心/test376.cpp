#include <iostream>
#include <vector>

class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int count = 1;
        int predif = 0;//记录前一个的差值
        for(int i=1;i<nums.size();i++)
        {
            int dif = nums[i] - nums[i-1];//当前的差值
            if((dif>0 && predif <=0)||(dif<0 && predif >=0))
            {
                count++;
                predif = dif;
            }
        }
        return count;
    }
};

int main()
{
    std::vector<int> nums = {1,7,4,9,2,5};
    Solution s;
    std::cout << s.wiggleMaxLength(nums) << std::endl;
    return 0;
}

//#define SMALL 2
// #define BIG 1

// class Solution {
// public:
//     int wiggleMaxLength(std::vector<int>& nums) 
//     {
//         if(nums.size()<2)
//         {
//             return nums.size();
//         }
//         int mode = 0;//1下一个要比前一个大，2下一个要小于前一个
//         if(nums[1]>nums[0])
//         {
//             mode = SMALL;
//         }
//         else if(nums[1]<nums[0])
//         {
//             mode = BIG;
//         }

//         for (int i = 1; i < nums.size()-2;)
//         {
//             if(nums[i+1]>nums[i]&&mode==SMALL)
//             {
//                 nums.erase(nums.begin()+i+1);
//                 continue;
//             }
//             else if(nums[i+1]<nums[i]&&mode==BIG)
//             {
//                 nums.erase(nums.begin()+i+1);
//                 continue;
//             }
//             else
//             {
//                 nums.erase(nums.begin()+i);
//                 continue;
//             }
//             i++;
//         }
//         return nums.size();
//     }
// };