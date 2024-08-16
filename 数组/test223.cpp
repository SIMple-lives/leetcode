#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        int overwidth = min(ax2, bx2) - max(ax1, bx1);
        int overheight = min(ay2, by2) - max(ay1, by1);
        int area3 = max(0, overwidth) * max(0, overheight);
        return area1 + area2 - area3;
    }
};

// class Solution {
// public:
//     int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
//         int area1 = (ax2 - ax1) * (ay2 - ay1);
//         int area2 = (bx2 - bx1) * (by2 - by1);
//         if(area1 == 0 || area2 == 0)
//         {
//             return area1 + area2;
//         }
//         if( ax1 == bx1 && ay1 == by1 && ax2 == bx2 && ay2 == by2)
//         {
//             return area1;
//         }
//         int overlap = 0;
//         if(ax1<bx1 && ax2 > bx1 && ay1>by1 && ay1 < by2)
//         {
//             overlap = (ax2 - bx1) * (by2 - ay1);
//         }
//         else if(ax1<bx1 && ax2 > bx1 && by1>ay1 && by1 < ay2)
//         {
//             overlap = (ax2 - bx1) * (ay2 - by1);
//         }
//         else if(bx1<ax1 && bx2 > ax1 && ay1>by1 && ay1 < by2)
//         {
//             overlap = (bx2 - ax1) * (by2 - ay1);
//         }
//         else if(bx1<ax1 && bx2 > ax1 && by1>ay1 && by1 < ay2)
//         {
//             overlap = (bx2 - ax1) * (ay2 - by1);
//         }
//         return area1 + area2 - overlap;
//     }
// };

int main()
{
    int ax1 = 0, ay1 = 0, ax2 = 0, ay2 = 0, bx1 = -1, by1 = -1, bx2 = 1, by2 = 1;
    Solution s;
    std::cout << s.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) << std::endl;
    return 0;
}