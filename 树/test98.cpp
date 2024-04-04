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

    void inOrder(TreeNode * root ,std::vector<int> &v)
    {
        if(root == nullptr)
        {
            return ;
        }
        inOrder(root->left,v);
        v.push_back(root->val);
        inOrder(root->right,v );
    }
    bool isValidBST(TreeNode* root) {
        //增加对边界的处理
        if(root == nullptr)
        {
            return true;
        }
        std::vector<int> ret ;
        inOrder(root, ret);
        for(int i =0 ;i<ret.size()-1;i++)
        {
            if(ret[i]>ret[i+1])
            {
                return false;
            }
        }
        return false;
    }
};