#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
            
    }
};

int main()
{
    int k=0;
    std::cin >> k;
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(-2);
    Solution s;
    long long sum=s.kSum(nums, k);
    //std::cout << sum << std::endl;
    return 0;
}

// class Solution {
// public:
//     std::vector<std::vector<int>> result;
//     std::vector<int> path;
//     void backtracking(std::vector<int> &nums)
//     {
//         if(path.size()==nums.size())
//         {
//             result.push_back(path);
//             return ;
//         }
//         for(int i = 0;i<nums.size();i++)
//         {
//             if(find(path.begin(),path.end(),nums[i])==path.end())
//             {
//                 path.push_back(nums[i]);
//                 backtracking(nums);
//                 path.pop_back();
//             }
//         }
//     }
//     void getCombine(std::vector<int> &nums)
//     {
//         path.clear();
//         backtracking(nums);
//     }
//     long long kSum(std::vector<int>& nums, int k) 
//     {
//         if(nums.size() == 0)
//         {
//             return 0;
//         }
//         result.clear();
//         path.clear();
//         getCombine(nums);
//         for(int i = 0;i < nums.size()-1;++i)
//         {
//             nums.pop_back();
//             getCombine(nums);
//         }
//         std::vector<long long> Sum;
//         for(std::vector<std::vector<int>>::iterator it=result.begin();it!=result.end();it++)
//         {
//             long long every=0;
//             for(std::vector<int>::iterator is=(*it).begin();is!=(*it).end();is++)
//             {
//                 std::cout << *is << " ";
//                 every+=*is;
//             }
//             std::cout << "\n";
//             Sum.push_back(every);
//         }
//         Sum.push_back(0);
//         sort(Sum.begin(),Sum.end());
//         return Sum[k-1];
//     }
// };

// class Solution {
// public:
//     std::vector<std::vector<int> > result;
//     std::vector<int> path;
//     void backtracking(std::vector<int>&nums,int n)
//     {   
//         if(path.size() == n)
//         {
//             result.push_back(path);
//             return;
//         }
//         for(int j =0;j<nums.size();j++)
//         {
//             if(find(path.begin(),path.end(),nums[j])==path.end())
//             {
//                 path.push_back(nums[j]);
//                 backtracking(nums,n);
//                 path.pop_back();
//             }
//         }
//     }
//     long long kSum(std::vector<int>& nums, int k) {
//         if(nums.size() == 0)
//         {
//             return 0;
//         }
//         result.clear();
//         for(int i = 1; i <= nums.size();i++)
//         {
//             path.clear();
//             backtracking(nums,i);
//         }
//         std::vector<long> Sum;
//         for(std::vector<std::vector<int>>::iterator it=result.begin();it!=result.end();it++)
//         {
//             int esum=0;
//             for(std::vector<int>::iterator is=(*it).begin();is!=(*it).end();is++)
//             {
//                 esum+=*is;
//             }
//             Sum.push_back(esum);
//         }
//         Sum.push_back(0);
//         sort(Sum.begin(),Sum.end());
//         return Sum[k-1];
//     }
// };
