#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> path;
    bool isPalindrome(std::string s,int i,int j)//
    {
        for(int m=i,n=j;m<n;m++,n--)
        {
            if(s[m]!=s[n])
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(const std::string &s,int index)
    {
        if(index>=s.size())
        {
            result.push_back(path);
            return ;
        }
        for(int i=index; i<s.size(); i++)
        {
            if(isPalindrome(s,index,i))
            {
                std::string std=s.substr(index,i-index+1);
                path.push_back(std);
            }
            else
            {
                continue;
            }
            backtracking(s,i+1);
            path.pop_back();
        }
    }
    std::vector<std::vector<std::string>> partition(std::string s) {
        result.clear();
        path.clear();
        backtracking(s,0);
        return result;
    }
};

int main()
{
    std::string s;
    std::cin>>s;
    Solution t;
    std::vector<std::vector<std::string>> ret=t.partition(s);
    for(auto &n:ret)
    {
        for(auto &m:n)
        {
            std::cout << m << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}