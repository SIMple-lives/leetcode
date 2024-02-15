#include <iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr)
        return 0;
        if(root->left==nullptr && root->right == nullptr)
        return 0;
        int leftnum=sumOfLeftLeaves(root->left);
        if(root->left && !root->left->left && !root->left->right)
        {
            leftnum += root->left->val;
        }
        int rightnum=sumOfLeftLeaves(root->right);
        int sum=leftnum+rightnum;
        return sum;
    }
};