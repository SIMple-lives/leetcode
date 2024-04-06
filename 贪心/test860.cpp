#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(auto n:bills)
        {
            if(n==5)
            {
                five++;
            }
            else if(n==10)
            {
                if(five>0)
                {
                    ten++;
                    five--;
                }
                else
                {
                    return false;
                }
            }
            else if(n==20)
            {
                if(ten>0&&five>0)
                {
                    ten--;
                    five--;
                    twenty++;
                }
                else if(five >=3)
                {
                    five-=3;
                    twenty++;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};