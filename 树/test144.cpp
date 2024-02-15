#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <algorithm>

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ret;
        if(root==NULL)
        return ret;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            ret.push_back(node->val);
            if(node->right)
            st.push(node->right);
            if(node->left)
            st.push(node->left);
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ret;
        TreeNode *cur=root;
        while(cur != NULL || !st.empty())
        {
            if(cur!=NULL)
            {
                st.push(cur);
                cur=cur->left;
            }
            else
            {
                cur=st.top();
                st.pop();
                ret.push_back(cur->val);
                cur=cur->right;
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *>st;
        vector<int> ret;
        if(root==NULL)
        return ret;
        st.push(root);
        while(!st.empty())
        {
            TreeNode *node=st.top();
            st.pop();
            ret.push_back(node->val);
            if(node->left)
            st.push(node->left);
            if(node->right)
            st.push(node->right);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};