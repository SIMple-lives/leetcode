#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) 
{
    if (!head || left == right) // 如果是空的，或者区间为0,则直接返回头结点
    {
        return head;
    }
    struct ListNode dummy;
    dummy.next = head;//虚拟头结点，用来返回最后的头结点
    struct ListNode *pre = &dummy;//移动位置的前一个结点
    struct ListNode *slow = head;//将其移动到区间的左端
    // Move 'slow' to the node before the reversing part
    for (int i = 1; i < left; ++i) 
    {
        pre = slow;
        slow = slow->next;
    }
    // Reverse the sub-list between 'left' and 'right'
    struct ListNode *cur = slow;
    struct ListNode *next = NULL;
    for (int i = 0; i <= right - left; ++i) //需要移动的结点数量
    {
        struct ListNode *temp = cur->next;//中间结点用来存储下一个结点
        cur->next = next;//将该结点的下一个结点置为前一个结点
        next = cur;//用来找到前面的结点
        cur = temp;//移动到下一个结点
    }
    pre->next = next;//将最后一个结点移动到头部
    slow->next = cur;//将移动前的结点移动到尾部
    return dummy.next;
}