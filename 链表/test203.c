#include<stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* temp;
    // 当头结点存在并且头结点的值等于val时
    while(head && head->val == val) {
        temp = head;
        // 将新的头结点设置为head->next并删除原来的头结点
        head = head->next;
        free(temp);
    }

    struct ListNode *cur = head;
    // 当cur存在并且cur->next存在时
    // 此解法需要判断cur存在因为cur指向head。若head本身为NULL或者原链表中元素都为val的话，cur也会为NULL
    while(cur && (temp = cur->next)) {
        // 若cur->next的值等于val
        if(temp->val == val) {
            // 将cur->next设置为cur->next->next并删除cur->next
            cur->next = temp->next;
            free(temp);
        }
        // 若cur->next不等于val，则将cur后移一位
        else
            cur = cur->next;
    }

    // 返回头结点
    return head;
}

/* struct ListNode* removeElements(struct ListNode* head, int val) 
{
   if(head==NULL) 
   {
        return head;
   }
   head->next=removeElements(head->next, val);
   return head->val==val?head->next:head;
} */

