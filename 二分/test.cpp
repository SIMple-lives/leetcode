#include <bits/stdc++.h>
// #include <algorithm>
using namespace std;

class Solution
{
public:
    Solution(vector<int> &nums) : nums(nums), b(1, 1) {};
    vector<int> nums;
    unordered_map<int, int> a;
    pair<int, int> b;
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 5, 6, 6, 6, 7, 8};
    Solution solution(nums);
    auto ret = lower_bound(solution.nums.begin(), solution.nums.end(), 3);
    auto ret1 = upper_bound(solution.nums.begin(), solution.nums.end(), 3);
    int index = ret - solution.nums.begin();
    int index1 = ret1 - solution.nums.begin();
    bool ifexit = binary_search(solution.nums.begin(), solution.nums.end(), 3);
    bool ifexit1 = binary_search(solution.nums.begin(), solution.nums.end(), 10);
    auto range = equal_range(solution.nums.begin(), solution.nums.end(), 6);
    cout << range.first - solution.nums.begin() << " " << range.second - solution.nums.begin() - 1 << endl;
    cout << "ifexit: " << ifexit << endl;
    cout << "ifexit1: " << ifexit1 << endl;
    cout << "The first occurrence of 3 is at index: " << index << endl;
    cout << "The last occurrence of 3 is at index: " << index1 << endl;
    cout << solution.b.first << " " << solution.b.second << endl;
    vector<int> v = {1, 3, 2, 9, 6, 3, 5, 6, 8, 7, 0, 4};
    vector<int> v1(v);

    stable_sort(v.begin(), v.end());
    sort(v1.begin(), v1.end(), [](int a, int b)
         { return a > b; });
    auto it = unique(v.begin(), v.end());
    auto it1 = unique(v1.begin(), v1.end());
    v.erase(it, v.end());
    v1.erase(it1, v1.end());
    for (auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    std::vector<int> v2 = {5, 3, 1, 4, 2};
    std::nth_element(v2.begin(), v2.begin() + 2, v2.end());
    for (auto i : v2)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}