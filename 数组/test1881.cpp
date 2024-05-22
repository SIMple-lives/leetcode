#include <string>
using namespace std;

// 贪心

class Solution {
public:
    string maxValue(string n, int x) {
        int len = n.size();
        int flag = 0;
        if (n[0] == '-'){
            for (int i = 1; i < len; ++i){
                if (n[i] - '0' > x){
                    n.insert(i, 1, x + '0');
                    flag = 1;
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < len; ++i){
                if (n[i] - '0' < x){
                    n.insert(i, 1, x + '0');
                    flag = 1;
                    break;
                }
            }

        }
        if(flag == 0){
            n += x + '0';
        }
        return n;
    }
};