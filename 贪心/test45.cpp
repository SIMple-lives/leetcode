#include <iostream>
#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) 
    {
        if(nums.size()==1) return 0;
        int current = 0;//记录现在的位置
        int area=0;//最大覆盖区域
        int next =0;//下一次最大的覆盖区域
        for(int i = 0;i < nums.size();i++)
        {
            next = std::max(nums[i]+i,next);
            if(i==current)
            {
                current = next;
                area++;
                if(current>=nums.size()-1)
                return area;
            }   
        }
        return area;
    }
};

int main()
{
    std::vector<int> v = {2,3,1,1,4};
    Solution s;
    std::cout<<s.jump(v)<<std::endl;
    return 0;
}