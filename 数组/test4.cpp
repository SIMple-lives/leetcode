#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {//先将两个数组合并，然后排序，根据下标返回中位数
        vector<int > Sum;
        Sum.insert(Sum.end(), nums1.begin(), nums1.end());
        Sum.insert(Sum.end(), nums2.begin(), nums2.end()); //合并两个数组
        sort(Sum.begin(), Sum.end());
        if(Sum.size()%2!=0)
        {
            return Sum[(Sum.size()-1)/2];
        }
        else
        {
            double a= Sum[(Sum.size()-1)/2];
            double b=Sum[Sum.size()/2];
            return (a+b)/2;
        }
    }
};

int main()
{
    Solution s;
    vector<int> v1;
    vector<int> v2;
    v1.push_back(1);
    v2.push_back(2);
    v1.push_back(3);
    v2.push_back(4);
    double ret=s.findMedianSortedArrays(v1, v2);
    cout << ret << endl;
}