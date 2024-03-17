#include<iostream>
using namespace std;
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> Q;
        vector<vector<int>> ret;
        if(root)
        {
            Q.push(root);
            while(!Q.empty())
            {
                vector<int> s;
                int size = Q.size();
                for(int i =0; i<size; i++)
                {
                    TreeNode* node = Q.front();
                    Q.pop();
                    s.push_back(node->val);
                    if(node->left)
                    Q.push(node->left);
                    if(node->right)
                    Q.push(node->right);
                }
                ret.push_back(s);
            }
        }   
        return ret; 
    }
};