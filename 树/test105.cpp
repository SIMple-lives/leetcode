#include <iostream>
using namespace std;
#include <vector>
#include <deque>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//在函数的参数列表加入每个容器的起始与结束位置，是由于在切割完中序数组后，要将第一个元素去除，而vector不提供头删
class Solution {
public:
     TreeNode* traversal (vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& preorder, int preorderBegin, int preorderEnd) {
        if (preorderBegin == preorderEnd) return NULL;

        int rootValue = preorder[preorderBegin]; // 注意用preorderBegin 不要用0
        TreeNode* root = new TreeNode(rootValue);

        if (preorderEnd - preorderBegin == 1) return root;

        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) 
        {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        // 切割中序数组
        // 中序左区间，左闭右开[leftInorderBegin, leftInorderEnd)
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        // 中序右区间，左闭右开[rightInorderBegin, rightInorderEnd)
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        // 切割前序数组
        // 前序左区间，左闭右开[leftPreorderBegin, leftPreorderEnd)
        int leftPreorderBegin =  preorderBegin + 1;
        int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin; // 终止位置是起始位置加上中序左区间的大小size
        // 前序右区间, 左闭右开[rightPreorderBegin, rightPreorderEnd)
        int rightPreorderBegin = preorderBegin + 1 + (delimiterIndex - inorderBegin);
        int rightPreorderEnd = preorderEnd;

        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd,  preorder, leftPreorderBegin, leftPreorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, preorder, rightPreorderBegin, rightPreorderEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0||inorder.size()==0)
        return NULL;
        return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
    }
};

//该方法用到了deque容器，使得可以对前序数组进行头部删除，使得代码与后序与中序求前序的结构完全一致.上一个是将下标传进去，这样起到删除头部元素的效果.
class Solution {
public:
    TreeNode*traversal(deque<int>& inorder,deque<int>&preorder)
    {
        if(inorder.size()==0||preorder.size()==0)
        return NULL;
        int rootval = preorder.front();
        TreeNode* root = new TreeNode(rootval);
        if(preorder.size()==1)
        return root;
        int index =0;
        for(index=0;index<inorder.size();index++)
        {
            if(inorder[index]==rootval)
            break;
        }
        deque<int> leftinorder (inorder.begin(),inorder.begin()+index);
        deque<int> rightinorder(inorder.begin()+index+1,inorder.end());
        preorder.pop_front();
        deque<int> leftpreorder(preorder.begin(),preorder.begin()+leftinorder.size());
        deque<int> rightpreorder(preorder.begin()+leftpreorder.size(),preorder.end());
        root->left =traversal(leftinorder,leftpreorder);
        root->right=traversal(rightinorder,rightpreorder);
        return root;
    } 

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0||inorder.size()==0)
        return NULL;
        deque<int> npreorder;
        deque<int> ninorder;
        for(int i=0; i<preorder.size(); i++)
        {
            npreorder.push_back(preorder[i]);
            ninorder.push_back(inorder[i]);
        }
        return traversal(ninorder, npreorder);
    }
};