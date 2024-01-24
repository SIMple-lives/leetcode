#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void delete(struct ListNode **L, int data) 
{
    struct ListNode *temp;
    while (*L && (*L)->val == data) {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
    struct ListNode *cur = *L;
    while (cur && cur->next) {
        if (cur->next->val == data) {
            temp = cur->next;
            cur->next = temp->next;
            free(temp);
        } else {
            cur = cur->next;
        }
    }
}

struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *cur = &dummy;
    int num;
    while (cur->next && cur->next->next) 
    {
        if (cur->next->val == cur->next->next->val) 
        {
            num = cur->next->val;
            delete(&(cur->next), num);
        } 
        else 
        {
            cur = cur->next;
        }
    }
    return dummy.next;
}

/* struct ListNode* deleteDuplicates(struct ListNode* head) //删除重复的哪一个数字，不是删除重复的数字
{
    if(head)
    {
        struct ListNode *cur=head;
        while(cur && cur->next)
        {
            if(cur->val==cur->next->val)
            {
                struct ListNode *temp=cur->next;
                cur->next=temp->next;
                free(temp);
            }
            else
            cur=cur->next;
        }
    }
    return head;
} */