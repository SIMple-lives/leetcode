#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if(numRows == 1)
        {
            return s;
        }
        std::vector<std::string> rows(numRows);
        for(int i = 0; i < s.size(); i++)
        {
            //计算当前字符应该放在哪一行
            //每2*numRows-2为一个周期
            int row = i % (2 * numRows - 2);
            //如果小于numRows，则放在当前行，否则放在numRows - (当前行 - numRows)
            if(row < numRows)
            {
                rows[row] += s[i];
            }
            else
            {
                rows[2 * numRows - 2 - row] += s[i];
            }
        }
        std::string res;
        for(auto row : rows)
        {
            res += row;
        }
        return res;
        
    }
};

int main()
{
    std::string s;
    int numsRows;
    std::cin>> s;
    std::cin>> numsRows;
    std::cout<< Solution().convert(s, numsRows);
    return 0;
}