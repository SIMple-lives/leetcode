#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


//利用了单调栈
//递增栈，从栈底向栈顶增加
class Solution {
public:
    int maximumScore(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::stack<int> st;
        std::vector<int> left(n), right(n);
        
        for (int i = 0; i < n; ++i) {//将数组中的元素按从小到大排序
            while (!st.empty() && nums[st.top()] >= nums[i]) //如果栈为空或者栈顶元素大于当前元素，就pop栈顶元素
            {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);//把当前元素的下标放入栈中
        }
        
        while (!st.empty()) st.pop();
        
        for (int i = n - 1; i >= 0; --i) //从右到左遍历数组,将栈顶元素放入right数组中
        {
            while (!st.empty() && nums[st.top()] >= nums[i]) 
            {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        int result = 0;
        for (int i = 0; i < n; ++i) 
        {
            if (left[i] < k && right[i] > k) 
            {
                result = std::max(result, nums[i] * (right[i] - left[i] - 1));
            }
        }
        return result;
    }
};

int main()
{
    std::vector<int> nums={1,4,3,7,4,5};
    int k;
    std::cin>>k;
    Solution s;
    std::cout << s.maximumScore(nums, k) << std::endl;
    return 0;
}

// class Solution {
// public:
//     int maximumScore(std::vector<int>& nums, int k) {
//         int left=k;
//         int right=k;
//         int score=nums[k];
//         int minnum=nums[left];
//         while(left>=0&&right<nums.size())
//         {
//             if(left-1>=0&&right+1<nums.size()&&nums[left-1]<nums[right+1])
//             {
//                 right++;
//                 minnum=std::min(minnum,nums[right]);
//             }
//             else if(left-1>=0&&nums[left-1]>nums[right]&&right+1<nums.size())
//             {
//                 left--;
//                 minnum=std::min(minnum,nums[left]);
//             }
//             score=std::max(score,minnum*(right-left+1));
//         }
//         while(left>=0)
//         {
//             left--;
//             minnum=std::min(minnum,nums[left]);
//             score=std::max(score,minnum*(right-left+1));
//         }
//         while(right<nums.size())
//         {
//             right++;
//             minnum=std::min(minnum,nums[right]);
//             score=std::max(score,minnum*(right-left+1));
//         }
//         return score;
//     }
// };
