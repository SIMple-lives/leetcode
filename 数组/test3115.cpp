#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:

    bool isprimer(int i)
    {
        if(i==1)
        {
            return false;
        }
        else
        {
            int j=0;
            for(j=2;j<=i/2;j++)
            {
                if(i%j==0)
                {
                    break;
                }
            }
            if(j>i/2)
            {
                return true;
            }
        }
        return false;
    }
    int maximumPrimeDifference(std::vector<int>& nums) 
    {
        std::vector<int> ret;
        for(int i=0;i<nums.size();i++)
        {
            if(isprimer(nums[i]))
            {
                ret.push_back(i);
            }
        }   
        sort(ret.begin(),ret.end());
        return ret[ret.size()-1]-ret[0];
    }
};

int main()
{

    std::vector<int> nums={4,2,9,5,3};

    Solution s;
    std::cout<<s.maximumPrimeDifference(nums);
    return 0;
}