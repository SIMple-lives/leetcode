#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <climits>
#include <unistd.h>
#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution  
{
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode *> Q;
        vector<int> ret;
        if(root)
        {
            Q.push(root);
            while(!Q.empty())
            {
                int size = Q.size();
                int max = INT_MIN;
                for(int i = 0; i < size;i++)
                {
                    TreeNode *node = Q.front();
                    Q.pop();
                    if(max<node->val)
                    {
                        max=node->val;
                    }
                    if(node->left)
                    Q.push(node->left);
                    if(node->right)
                    Q.push(node->right);
                }
                ret.push_back(max);
            }
        }
        return ret;
    }
};

void cleanup1() {
    printf("Cleanup 1\n");
}

void cleanup2() {
    printf("Cleanup 2\n");
}

int main() {
    atexit(cleanup1);
    atexit(cleanup2);
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    pid_t pid = fork();
    if (pid == -1) 
    {
        std::cout << "Error" << std::endl;
    } else if (pid == 0) 
    {
        char *const argv[] = {"ls", "-l", NULL};
        execvp("ls", argv);
    } 
    else 
    {
        std::cout << "Parent" << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << a + b << std::endl;
        cout << pid << endl;
    }

    return 0;
}