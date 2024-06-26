#include <vector>
#include <algorithm>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(),citations.end());
        int h=0;
        int i=citations.size()-1;
        while(i>=0 && citations[i]>h)
        {
            h++;
            i--;
        }
        return h;
    }
};