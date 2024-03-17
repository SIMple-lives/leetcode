#include <stdio.h>
#include <stdlib.h>

struct  ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *init()
{
    struct ListNode*N=(struct ListNode *)malloc(sizeof(struct ListNode));
    N->next=NULL;
    N->val=0;
    return N;
}

void insert(struct ListNode *L,int data)
{
    struct ListNode *node=(struct ListNode *)malloc(sizeof(struct ListNode));
    node->next=L->next;
    node->val=data;
    L->next=node;
}

void print(struct ListNode *L)
{
    struct ListNode*node=L->next;
    while(node)
    {
        printf("%d ->",node->val);
        node=node->next;
    }
    printf("NULL\n");
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
   //首先求出两个链表的长度
   int  lenA=0;
   int  lenB=0;
   struct ListNode *A=headA;
   struct ListNode *B=headB;
   while(A)
   {
       lenA++;
       A=A->next;
   }
   while(B)
   {
       lenB++;
       B=B->next;
   }
   int index=0;//求出两个链表的差值
   if(lenA>lenB)//将对应长的链表进行赋值，对齐到对应的位置上
   {
       index=lenA-lenB;
       A=headA;
       B=headB;
   }
   else
   {
       index=lenB-lenA;
       A=headB;
       B=headA;
   }
   while(index--)
   {
       A=A->next;
   }
   while(A)//进行判断
   {
       if(A==B)
       {
           return A;
       }
       A=A->next;
       B=B->next;
   }
   return NULL;
}

int main()
{
    struct ListNode *L=init();
    insert(L,1);
    insert(L,2);
    insert(L,3);
    insert(L,4);
    print(L);
    return 0;
}