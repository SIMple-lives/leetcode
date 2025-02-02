#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    //计算满足条件的子数组个数
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0; //窗口内元素和
        int count  = 0; //满足条件的子数组个数
        for(int i = 0; i < arr.size();i++) {
            sum += arr[i]; //计算窗口内元素和
            if ( i < k-1) {
                continue;
            }
            if(sum >= threshold*k) {
                count++;
            }
            sum -= arr[i-k+1];
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> arr = {2,2,2,2,5,5,5,8};
    int k = 3;
    int threshold = 4;
    cout << s.numOfSubarrays(arr,k,threshold) << endl;
    return 0;
}