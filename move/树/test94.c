#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}TreeNode;

void creatTree(TreeNode **T,char *ch,int *index)
{
    char data;
    data=ch[*index];
    *index+=1;
    if(data=='#')
    {
        *T=NULL;
    }
    else
    {
        *T=(TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data=data;
        creatTree(&((*T)->lchild),ch,index);
        creatTree(&((*T)->rchild),ch,index);
    }
}

void printTree(TreeNode *T)//前序遍历
{
    if(T==NULL)
    {
        return ;
    }
    else
    {
        //先输出值，然后在分别遍历左子树与右子树
        printf("%c ",T->data);
        printTree(T->lchild);
        printTree(T->rchild);
    }
}

void inprintTree(TreeNode * T)//中序遍历
{
    if(T==NULL)
    {
        return ;
    }
    else
    {
        inprintTree(T->lchild);
        printf("%c ",T->data);
        inprintTree(T->rchild);
    }
}

void poxprintTree(TreeNode *T)
{
    if(T==NULL)
    {
        return ;
    }
    else
    {
        poxprintTree(T->lchild);
        poxprintTree(T->rchild);
        printf("%c ",T->data);
    }
}

int main()
{
    char s[100];
    scanf("%s",s);
    TreeNode *T;
    int index=0;
    creatTree(&T,s,&index);
    printTree(T);
    printf("\n");
    return 0;
}