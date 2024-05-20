#include <vector>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) 
    {
        int n = arr.size();
        int index = 0;
        int cnt = 0;
         for (int i = 1; i < n && cnt < k; i++) 
         {
            if (arr[index] > arr[i]) 
            {
                cnt++;
            }
            else 
            {
                index = i;
                cnt = 1;
            }
        }
        return arr[index];
    }
};