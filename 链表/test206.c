#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int data;
    struct Node* next;
};

struct ListNode* reverseList(struct ListNode* head)
{
   struct ListNode*pre=NULL;
   struct ListNode* cur;
   while(head)
   {
      cur->next=head->next;//这个是后面后移动的
      head->next=pre;//这个是前面先移动的
      pre=head;//head向后yid
      head=cur;//赋值
   }
   return pre;
}

struct Node *creatlist()
{
    struct ListNode*head=(struct Node *)malloc(sizeof(struct ListNode));
    head->next=NULL;
    return head;
}

int main()
{
    struct Node*head=creatlist();
    reverseList(head);
    return 0;
}