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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ret;
        for(int i=0;i<queries.size();i++)
        {
            vector<int> v= {-1,-1};
            int query= queries[i];
            TreeNode* node =root;
            while(node)
            {
                if(node->val<=query)
                {
                    v[0]=node->val;
                    node=node->right;
                }
                else
                {
                    v[1]=node->val;
                    node=node->left;
                }
            }
            ret.push_back(v);
        }   
        return ret;     
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
//                 int index=0;
//                 int j=0;
//                 for(j=0;j<num.size();j++)
//                 {
//                     if(num[j]<queries[i]&&num[j+1]>queries[i])
//                     {
//                         index = j;
//                         break;
//                     }
//                 }
//             }
//             result.push_back(v);
//         }
//        return result;
//     }
// };