#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m+n);
        // for(vector<int>::iterator it=nums2.begin();it!=nums2.end();it++)
        // {
        //     nums1.push_back(*it);
        // }
        int index =0;
        for(size_t i=m;i<m+n;i++)
        {
            nums1[i]=nums2[index++];
        }
        sort(nums1.begin(),nums1.end());
    }

};

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(6);
    Solution s;
    s.merge(v,3,v1,3);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout << *it << endl;
    }
    return 0;
}