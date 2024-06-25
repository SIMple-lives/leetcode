#include <vector>
#include <algorithm>

// class Solution {
// public:
    // int kthSmallest(std::vector<std::vector<int>>& matrix, int k) 
    // {
        // int m = matrix[0].size();
        // int second = k%m;
        // if(second==0)
        // {
            // return matrix[k/m-1][m-1];
        // }
        // else
        // {
            // return matrix[k/m][second-1];
        // }  
    // }
// };

class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        std::vector<int> ret;
        for(auto i :matrix)
        {
            for(auto j:i)
            {
                ret.push_back(j);
            }
        }
        std::sort(ret.begin(),ret.end());
        return ret[k-1];
    }
};