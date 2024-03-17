#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode *init()
{
    struct ListNode *L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=NULL;
    L->val=0;
    return L;
}

void addtail(struct ListNode *L,int data)
{
    struct ListNode *node=(struct ListNode *)malloc(sizeof(struct ListNode));
    node->next=NULL;
    node->val=data;
    while(L->next)
    {
        L=L->next;
    }
    L->next=node;
}

struct ListNode* partition(struct ListNode* head, int x) 
{
    if(head)
    {
        struct ListNode *A=init();//存小的
        struct ListNode *B=init();//存大的
        while(head)
        {
            if(head->val<x)
            {
                addtail(A,head->val);
            }
            else
            {
                addtail(B,head->val);
            }
            head=head->next;
        }
        struct ListNode *cur=A;
        while(cur->next)
        {
            cur=cur->next;
        }
        cur->next=B->next;
        free(B);
        cur=A;
        A=A->next;
        free(cur);
        return A;
    }
    return head;
}