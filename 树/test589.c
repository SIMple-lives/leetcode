#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}TreeNode;

void creatTree(TreeNode **T,int *data,int *index)
{
    int val=data[*index];
    *index+=1;
    if(val=='-1')
    {
        *T=NULL;
    }
    else
    {
        *T=(TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data=val;
        creatTree(&((*T)->lchild),data,index);
        creatTree(&((*T)->rchild),data,index);
    }
}

void Preorder(int *ret,int *returnSize,struct Node *T)
{
    if(T==NULL)
    {
        return ;
    }
    ret[(*returnSize)++]=T->val;
    for(int i=0;i<T->numChildren;i++)
    {
        Preorder(ret,returnSize,T->children[i]);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    int *ret=(int *)malloc(sizeof(int)*10000);
    *returnSize=0;
    Preorder(ret,returnSize,root);
    return ret;
}