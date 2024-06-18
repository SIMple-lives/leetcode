#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>


class Solution {
public:
    std::string discountPrices(std::string sentence, int discount) {
        //初始化sin,sout
        //sout设置为固定两位小数
        //遍历sentence
        //如果当前字符串以$开头，且长度大于1，则判断是否为有效价格
        //如果是有效价格，则计算打折后的价格，并添加到sout中
        //否则，直接将当前字符串添加到sout中
        //返回sout
        std::stringstream sin(sentence), sout;
        //设置sout为固定两位小数
        sout << std::fixed << std::setprecision(2);

        std::string word;
        while (sin >> word) 
        {
            if (word[0] == '$' && word.size() > 1) 
            {
                //判断是否为有效价格
                bool isValidPrice = true;
                for (size_t i = 1; i < word.size(); ++i) 
                {
                    //判断是否为数字或.
                    if (!isdigit(word[i]) && word[i] != '.') 
                    {
                        //如果不是数字或.，则不是有效价格
                        isValidPrice = false;
                        break;
                    }
                }
                if (isValidPrice) 
                {
                    try 
                    {
                        double price = stod(word.substr(1)) * (1.0 - discount / 100.0);
                        sout << '$' << price;
                    } 
                    catch (const std::invalid_argument& e) 
                    {
                        sout << word; // In case of conversion failure, keep the original word
                    }
                } 
                else 
                {
                    sout << word;
                }
            } 
            else 
            {
                sout << word;
            }
            sout << " ";
        }
        std::string ans = sout.str();
        ans.pop_back(); // Remove the trailing space
        return ans;
    }
};

int main()
{
    std::string sentence = "there are $1 $2 and 5$ candies in the shop";
    int discount = 50;

    Solution solution;
    std::string result = solution.discountPrices(sentence, discount);

    std::cout << result << std::endl;
    return 0;
}