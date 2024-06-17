#include <iostream>
#include <vector>

// 42. Trapping Rain Water
//dp
//找到每个位置的左右最高值的最小值减去当前位置的高度，就是该位置能存多少水
//每个下标处能存储的水量等于该下标处左右最高值的最小值减去该下标处的高度
//遍历每个下标，累加每个下标处能存储的水量

class Solution {
public:
    int trap(std::vector<int>& height) 
    {
        int area =0;
        int n = height.size();
        if(n==0)
        {
            return 0;
        }
        //左边
        //从左往右遍历，记录每个位置左边最高的值
        std::vector<int> left (n);
        left[0]=height[0];
        for(int i=1;i<n;i++)
        {
            left[i]=std::max(height[i],left[i-1]);
        }
        //右边
        //从右往左遍历，记录每个位置右边最高的值
        std::vector<int> right(n);
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=std::max(height[i],right[i+1]);
        }
        for(int i=0;i<n;i++)
        {
            //每个位置能存的水量等于该位置左右最高值的最小值减去该位置的高度
            area+=std::min(left[i],right[i])-height[i];
        }
        return area;
    }
};  

int main()
{
    //std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::vector<int> height = {4,2,0,3,2,5};
    Solution s;
    std::cout << s.trap(height) << std::endl;

    return 0;
}