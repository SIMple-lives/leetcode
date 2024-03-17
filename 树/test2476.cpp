#include <stdio.h>
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
    void findClosest(TreeNode* root, int query, int& mini, int& maxi) {
        TreeNode* node = root;
        while (node) {
            if (node->val == query) 
            {
                mini = node->val;
                maxi = node->val;
                return;
            } else if (node->val < query) {
                mini = node->val;
                node = node->right;
            } else {
                maxi = node->val;
                node = node->left;
            }
        }
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> result;
        for (int i = 0; i < queries.size(); i++) {
            int query = queries[i];
            int mini = -1, maxi = -1;
            findClosest(root, query, mini, maxi);
            vector<int> v;
            v.push_back(mini);
            v.push_back(maxi);
            result.push_back(v);
        }
        return result;
    }
};

// class Solution {
// public:
//     vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {//初始思路，有点麻烦没有注意到题目中的二叉搜索树
//         vector<int> num;
//         stack<TreeNode*> s;
//         s.push(root);
//         while(!s.empty()) 
//         {
//             int size= s.size();
//             for(int i=0; i<size; i++)
//             {
//                 TreeNode*node=s.top();
//                 s.pop();
//                 num.push_back(node->val);
//                 if(node->left)
//                 s.push(node->left);
//                 if(node->right)
//                 s.push(node->right);
//             }
//         }
//         sort(num.begin(),num.end());
//         vector<vector<int>> result;
//         for(int i=0;i<queries.size();i++)
//         {
//             vector<int> v;
//             vector<int>::iterator it=find(num.begin(), num.end(), queries[i]);
//             if(it!=num.end())
//             {
//                 v.push_back(*it);
//                 v.push_back(*it);
//             }
//             else
//             {
//                 v[0]=-1;
//                 v[1]=-1;
//                 for(int j=0;j<num.size()-1;j++)
//                 {
//                     v[0]=num[j];
//                     if(num[j]<queries[i]&&num[j+1]>queries[i])
//                     {
//                         v[1]=num[j+1];
//                         break;
//                     }
//                 }
//             }
//             result.push_back(v);
//         }
//        return result;
//     }
// };