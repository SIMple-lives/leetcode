#include <iostream>
#include <vector>

//1234321
//1201240
//两次遍历，第一次从左往右遍历，第二次从右往左遍历，保证中间孩子分到的糖果.
class Solution {
public:
    int candy(std::vector<int>& ratings) 
    {
        std::vector<int> candies(ratings.size(), 1);
        for(int i=1;i<ratings.size();i++)//左边的孩子小于右边的孩子.
        {
            if(ratings[i]>ratings[i-1]) 
            {
                candies[i]=candies[i-1]+1;
            }
        }
        for(int i = ratings.size()-2;i>=0;i--)//右边的孩子小于左边的孩子
        {
            if(ratings[i]>ratings[i+1])
            {
                candies[i]=std::max(candies[i],candies[i+1]+1);//保证中间的孩子分到的糖果.
            }
        }
        int ret = 0;
        for(auto candy:candies)
        {
            ret+=candy;
        }
        return ret;
    }
};

int main()
{
    std::vector<int> ratings = {1,2,3,4,3,2,1};
    Solution s;
    std::cout << s.candy(ratings)<<std::endl;
    return 0;
}