#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ret;
        for(int i = 1;i<10;i++)
        {
            int num = i;
            for(int j = i+1;j<10;j++)
            {
                num = num * 10 +j;
                if(num >= low && num <= high)
                {
                        ret.push_back(num);
                }
            }
        }
        return ret;
    }
};

int main()
{
    int low, high;
    cin >> low >> high;
    Solution s;
    vector<int> res = s.sequentialDigits(low, high);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}