#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) 
{
    if(head)
    {
        int len=1;
        struct ListNode *cur=head;
        while(cur->next)
        {
            len++;
            cur=cur->next;
        }
        int newk=len-k%len;
        cur->next=head;
        for(int i=0;i<newk;i++)
        {
            cur=cur->next;
        }
        struct ListNode *ret=cur->next;
        cur->next=NULL;
        return ret;
    }
}