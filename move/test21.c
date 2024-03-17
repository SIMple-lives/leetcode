#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* init()
{
    struct ListNode *L=(struct ListNode *)malloc(sizeof(struct ListNode));
    L->val=0;
    L->next=NULL;
    return L;
}

void addtail(struct ListNode *L,int data)
{
    struct ListNode *node=(struct ListNode *)malloc(sizeof(struct ListNode));
    while(L->next)
    {
        L=L->next;
    }
    node->val=data;
    node->next=NULL;
    L->next=node;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    struct ListNode *L=init();
    while(list1 || list2)
    {
        if(list1 && (!list2 || list1->val <= list2->val))//当l1小时先加l1,或者l2为空
        {
            addtail(L,list1->val);
            list1=list1->next;
        }
        else
        {
            addtail(L,list2->val);
            list2=list2->next;
        }
    }
    struct ListNode *temp=L;
    L=L->next;
    free(temp);
    return L;
}