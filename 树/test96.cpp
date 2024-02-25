#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int numTrees(int n) 
    {
        vector<int> v(n+1,0);
        v[0]=1;
        v[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                v[i]+=v[j-1]*v[i-j];
            }
        }
        return v[n];
    }
};

int main()
{
    Solution s;
    cout << s.numTrees(3) << endl;
    return 0;
}