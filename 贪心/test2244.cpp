#include <vector>
#include <unordered_map>

using namespace std;

// 贪心
// 先统计每个任务的数量，然后遍历每个任务的数量，如果数量为1，则无法完成，返回-1；否则，如果数量能被3整除，则直接除以3；否则，加上余数。最后，返回所有任务的最小轮数。
// 时间复杂度：O(n)，其中 n 是数组 tasks 的长度。遍历数组 tasks 的每个元素，计算每个任务的数量。
// 空间复杂度：O(n)，其中 n 是数组 tasks 的长度。需要使用哈希表来存储每个任务的数量。
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> cnt;
        for (int t : tasks) {
            cnt[t]++;
        }
        int res = 0;
        for (auto [a, v] : cnt) 
        {
            if (v == 1) {
                return -1;
            } else if (v % 3 == 0) {
                res += v / 3;
            } else {
                res += v / 3 + 1;
            }
        }
        return res;

    }
};