#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> C(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i) {
            C[i].resize(i + 1);
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
        return C[rowIndex];
    }
};

int main()
{

    int index ;
    cin >> index;
    Solution s;
    vector<int> res = s.getRow(index);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}