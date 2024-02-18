#include <iostream>
using namespace std;
#include <string>
#include <vector>

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
    void traversal(TreeNode *cur,vector<int>&path,vector<string>& result)
    {
        path.push_back(cur->val);
        if(cur->left==NULL && cur->right==NULL)
        {
            string sPath;
            for(int i=0;i<path.size()-1;i++)
            {
                sPath += to_string(path[i]);//to_string将基本数据类型转换为字符串
                sPath += "->";
            }
            sPath+=to_string(path[path.size()-1]);
            result.push_back(sPath);
        }
        if (cur->left) 
        { // 左 
            traversal(cur->left, path, result);
            path.pop_back(); // 回溯
        }
        if (cur->right) 
        { // 右
            traversal(cur->right, path, result);
            path.pop_back(); // 回溯
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> result;
        vector<int> path;
        if(root==NULL)
        return result;
        traversal(root, path, result);
        return result;
    }
};
