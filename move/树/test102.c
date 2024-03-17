#include <stdio.h>
#include<stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct Queue
{
    struct TreeNode *data;
    struct Queue *next;
    struct Queue *prev;
}Queue;

Queue * initQueue()
{
    Queue *Q=(Queue *)malloc(sizeof(Queue));
    Q->data=NULL;
    Q->next=Q;
    Q->prev=Q;
    return Q;
}

void enQueue(Queue *Q,struct TreeNode *data)//尾插法
{
    Queue *node=(Queue *)malloc(sizeof(Queue));
    node->data=data;
    if(Q->next==Q)
    {
        node->next=Q;
        node->prev=Q;
        Q->prev=node;
        Q->next=node;
    }
    else
    {
        node->next=Q;
        node->prev=Q->prev;
        Q->prev->next=node;
        Q->prev=node;
    }
}

int isEmpty(Queue *Q)
{
    if(Q->next==Q)
    {
        return 1;
    }
    return 0;
}

Queue *dequeuq(Queue *Q)
{
    if(isEmpty(Q))
    {
        return NULL;
    }
    else
    {
        Queue *node=Q->next;
        Q->next->next->prev=Q;
        Q->next=Q->next->next;
        return node;
    }
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) 
{
    int **ret=(int *)malloc(sizeof(int *)*2000);
    *returnSize=0;
    if(root==NULL)
    {
        return NULL;
    }   
    *returnColumnSizes=(int *)malloc(sizeof(int)*2000);
    struct TreeNode *Queue[2000];//建立队列
    int front=0;//队头指针
    int rear=0;//队尾指针
    struct TreeNode *cur;
    Queue[rear++]=root;
    while(front!=rear)
    {
        int colSize = 0;
        int last = rear;
        ret[*returnSize] = (int*)malloc(sizeof(int) * (last - front));
        while(front < last)
        {
            cur = Queue[front++];
            ret[*returnSize][colSize++] = cur ->val;
            if(cur -> left != NULL)
                Queue[rear++] = cur -> left;
            if(cur -> right != NULL)
                Queue[rear++] = cur -> right;
        }
        (*returnColumnSizes)[*returnSize] = colSize;
        (*returnSize)++;
    }
    return ret;
}