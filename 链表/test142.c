#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) //判断链表是否有环可以使用快慢指针法，分别定义 fast 和 slow 指针，从头结点出发，fast指针每次移动两个节点，slow指针每次移动一个节点，如果 fast 和 slow指针在途中相遇 ，说明这个链表有环。
{
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)//如果有环的话，那么从相遇地点和头结点同时出发一个指针，当两个指针相遇的时候就是环的入口结点
        {
            struct ListNode *find=head;
            while(find!=slow)
            {
                find=find->next;
                slow=slow->next;
            }
            return slow;
        }
    }
    return NULL;
}