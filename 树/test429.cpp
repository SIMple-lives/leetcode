#include <iostream>
using namespace std;
#include <queue>
#include <vector>

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> Q;
        vector<vector<int>> ret;
        if(root)
        {
            Q.push(root);
            while(!Q.empty())
            {
                int size = Q.size();
                vector<int> s;
                for(int i=0;i<size;i++)
                {
                    Node *node=Q.front();
                    Q.pop();
                    s.push_back(node->val);
                    int newsize = node->children.size();
                    for(int j=0;j<newsize;j++)
                    {
                        if(node->children[j])
                        {
                            Q.push(node->children[j]);
                        }
                    }
                }
                ret.push_back(s);
            }
        }
        return ret;
    }
};