#include <string>
#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode * mergeTwo(ListNode *a, ListNode *b)
    {
        if (!a || !b) 
        {
            return a ? a : b;
        }
        ListNode* aptr = a;
        ListNode* bptr = b;
        ListNode* head = new ListNode(0); // 初始化 head 指针
        ListNode* cur = head; // 使用 cur 指针代替 head 进行操作
        while (aptr && bptr) {
            if (aptr->val > bptr->val) {
                cur->next = bptr;
                bptr = bptr->next;
            } else {
                cur->next = aptr;
                aptr = aptr->next;
            }
            cur = cur->next;
        }
        cur->next = (aptr ? aptr : bptr);//接替某一链表剩余的结点
        ListNode* result = head->next;
        delete head; // 释放临时节点
        return result;
    }
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* ret =nullptr;
        for(int i=0;i<lists.size();i++)
        {
            ret=mergeTwo(ret,lists[i]);//每两个生成一个链表，然后在不断进行两两合并
        }
        return ret;
    }
};