#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <queue>

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int num ;
        while(!Q.empty()) 
        {
            int size = Q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *node=Q.front();
                Q.pop();
                if(i==0)
                {
                    num=node->val;
                }
                if(node->left)
                Q.push(node->left);
                if(node->right)
                Q.push(node->right);
            }
        }
        return num;
    }
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
    }
};