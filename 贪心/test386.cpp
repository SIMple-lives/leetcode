#include <vector>

class Solution {
public:
    std::vector<int> lexicalOrder(int n) {
        std::vector<int> v(n);
        int singal = 1;
        for(int i=0;i<n;i++)
        {
            v[i]=singal;
            if(singal*10<=n)
            {
                singal*=10;
            }
            else
            {
                while(singal%10==9||singal+1>n)
                {
                    singal/=10;
                }
                singal++;
            }
        }
        return v;
    }
};