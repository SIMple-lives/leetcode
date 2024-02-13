#include <iostream>
using namespace std;
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<double> ret;
        if(root)
        {
            Q.push(root);
            while(!Q.empty())
            {
                int size = Q.size();
                double sum=0;
                for(int i = 0; i < size;i++)
                {
                    TreeNode* node = Q.front();
                    Q.pop();
                    sum+=node->val;
                    if(node->left)
                    Q.push(node->left);
                    if(node->right)
                    Q.push(node->right);
                }
                ret.push_back(sum/size);
            }
        }
        return ret;
    }
};
