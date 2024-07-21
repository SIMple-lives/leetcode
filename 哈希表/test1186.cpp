#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    int maximumSum(std::vector<int>& arr) {
        int a=arr[0];
        int b=0;
        int c=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            b=std::max(a,b+arr[i]);
            a=std::max(a,0)+arr[i];
            c=std::max(c,std::max(a,b));
        }
        return c;
    }
};

// class Solution {
// public:
//     int maximumSum(std::vector<int>& arr) {
//         std::unordered_map<int,int> mp;
//         int n = arr.size();
//         int sum = 0;
//         for(int i =0 ;i<n;i++)
//         {
//             sum+=arr[i];
//             if(arr[i]<0)
//             {
//                 if(mp.find(arr[i]) != mp.end())
//                 {
//                     mp[arr[i]]++;
//                 }
//                 else 
//                 {
//                     mp[arr[i]] = 1;
//                 }
//             }
//         }
//         std::vector<int> v;
//         for(auto it = mp.begin();it!=mp.end();it++)
//         {
//             v.push_back(it->first*it->second);
//         }
//         std::sort(v.begin(),v.end());
//         for(int i=0;i<v.size();i++)
//         {
//             std::cout << v[i] << "a";
//         }
//         std::cout << std::endl;
//         return arr[0];
//         // if(v.size()==1)
//         // {
//         //     if(sum==v[0])
//         //     {
//         //         return arr[0];
//         //     }
//         //     else 
//         //     {
//         //         return sum-v[0];
//         //     }
//         // }
//         // else 
//         // {
//         //     return sum - v[0];
//         // }
//     }
// };

int main()
{
    std::vector<int> arr = {1,-2,0,3};
    std::vector<int> arr1 = {1,-2,-2,3};
    std::vector<int> arr2 = {-1,-1,-1,-1};
    Solution s;
    std::cout << s.maximumSum(arr) << std::endl;
    std::cout << s.maximumSum(arr1) << std::endl;
    std::cout << s.maximumSum(arr2) << std::endl;
    return 0;
}