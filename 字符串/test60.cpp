#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string getPermutation(int n, int k) 
    {
        std::vector<int> factorial(n, 1);//创建数组，将每一个元素初始化为1，用来精确判断每一位的数字
        for (int i = 1; i < n; ++i) 
        {
            factorial[i] = factorial[i - 1] * i;//通过循环将对应的元素存储为对应的阶乘
        }
        std::vector<int> nums(n);//创建数组，并将每一个元素初始化为1-n的连续整数,用来决定对应元素的下标
        for (int i = 0; i < n; ++i) 
        {
            nums[i] = i + 1;
        }
        --k; // Convert k to 0-based index
        std::string result;//存储结果
        for (int i = n - 1; i >= 0; --i) 
        {
            int index = k / factorial[i];//用k除以总的排列个数，向下取整
            result += ('0' + nums[index]);
            // Remove the chosen number
            nums.erase(nums.begin() + index);
            // Update k for the next iteration
            k %= factorial[i];//将剩余的数字继续进行该步骤
        }
        return result;
    }
};

int main()
{
    int n=0;
    int k=0;
    std::cin>>n>>k;
    Solution s;
    std::string ret=s.getPermutation(n, k);
    std::cout << ret << std::endl;
    return 0;
}

// class Solution {//超出了时间的限制
// public:
//     std::vector<std::vector<int>> result;
//     std::vector<int> path;
//     void backtracking(int n)
//     {   
//         if(path.size() == n)
//         {
//             result.push_back(path);
//             return ;
//         }
//         for(int i =1 ;i<=n;i++)
//         {
//             if(find(path.begin(),path.end(),i)==path.end())
//             {
//                 path.push_back(i);
//                 backtracking(n);
//                 path.pop_back();
//             }
//         }
//     }
//     std::string getPermutation(int n, int k) 
//     {
//         result.clear();
//         path.clear();
//         backtracking(n);
//         sort(result.begin(),result.end());
//         std::string s;
//         for (auto &num : result[k - 1]) {
//             s.push_back('0' + num);  // 将数字转换为字符并拼接到字符串中
//         }
//         return s;
//     }
// };
