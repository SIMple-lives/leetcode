#include <iostream>
#include <string>

class Solution {
public:
    std::string getHint(std::string secret, std::string guess) 
    {
        int A=0;//公牛
        int B=0;//奶牛
        int ret1[10]={0};
        int ret2[10]={0};
        for (size_t i = 0; i < guess.size(); i++)
        {
            if (guess[i] == secret[i])//找到公牛数
            {
                A++;
            }
            ret1[secret[i] - '0']++;
            ret2[guess[i] - '0']++;
        }
        
        for (int i = 0; i < 10; i++)//所有奶牛数
        {
            if (ret2[i] == 0)
            {
                continue;
            }
            else if (ret2[i] > ret1[i])
            {
                B += ret1[i];
            }
            else
            {
                B += ret2[i];
            }
        }
        B-=A;//减去即可
        std::string ret;
        std::string s1=std::to_string(A);//将数字转换为字符串
        std::string s2=std::to_string(B);
        ret+=s1;
        ret.push_back('A');
        ret+=s2;
        ret.push_back('B');
        return ret;
    }
};

int main()
{   
    std::string secret;
    std::string guess;
    std::cin>>secret>>guess;
    Solution s;
    std::string ret=s.getHint(secret, guess);
    std::cout << ret << std::endl;
    return 0;
}