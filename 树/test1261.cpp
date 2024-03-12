#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
public:
    vector<int> num;
    void initTree(TreeNode *node)
    {
        if (node->left)//还原树的左结点，并将其数据加入数组.
        {
            node->left->val = (2 * node->val) + 1;
            num.push_back(node->left->val);
            initTree(node->left);
        }
        if (node->right)//还原树的右结点.
        {
            node->right->val = (2 * node->val) + 2;
            num.push_back(node->right->val);
            initTree(node->right);
        }
    }

    FindElements(TreeNode* root) {
        if (root)
        {
            root->val = 0;
            num.push_back(root->val);
            initTree(root);
        }
    }

    bool find(int target) {
        return std::find(num.begin(), num.end(), target) != num.end();
    }
};
// class FindElements {
// public:
//     TreeNode *mroot;
//     void initTree(TreeNode *root,TreeNode *mroot) 
//     {
//         if(root->left)
//         mroot->left->val=(2*root->val)+1;
//         if(root->right)
//         mroot->right->val=(2*root->val)+2;
//         initTree(root->left,mroot->left);
//         initTree(root->right,mroot->right);
//     }
//     FindElements(TreeNode* root) {
//         if(root)
//         {
//             mroot->val=0;
//         }
//         initTree(root,mroot);
//     }
    
//     bool find(int target) {
//         if(target==0)
//         {
//             return true;
//         }
//         TreeNode *mfind=mroot;
//         while()
//     }
// };