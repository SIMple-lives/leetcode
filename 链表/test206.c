#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct ListNode* reverseList(struct ListNode* head)
{
   struct Node*pre=head;
   struct Node* cur=head->next;
   while(head)
   {
      cur->next=head->next;
      head->next=pre;
      pre=head;
      head=cur;
   }
}

struct Node *creatlist()
{
    struct Node*head=(struct Node *)malloc(sizeof(struct Node));
    head->next=NULL;
    return head;
}

int main()
{
    
    struct Node*head=creatlist();
    reverseList(head);
    return 0;
}