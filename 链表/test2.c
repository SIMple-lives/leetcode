#include <stdio.h>

struct ListNode {

    int val;
    struct ListNode *next;
};

struct ListNode *initListNode()
{
    struct ListNode *L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=NULL;
    L->val=0;
    return L;
}

void addtail(struct ListNode *L,int data)
{
    struct ListNode *node=(struct ListNode *)malloc(sizeof(struct ListNode));
    node->val=data;
    L=L->next;
    while(L)
    {
        L=L->next;
    }
    node->next=NULL;
    L->next=node;
}

void detail(struct ListNode*L)
{
    if(L)
    {
        struct ListNode *pre=L->next;
        while(pre)
        {
            if(pre->next!=NULL)
            {
                pre->next->val+=pre->val/10;
                pre->val%=10;
            }
            else
            {
                addtail(L,pre->val/10);
                pre->val%=10;
                pre=pre->next;
            }
            pre=pre->next;
        }
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) 
{
    struct ListNode* num = initListNode();//初始化一个结点
    struct ListNode* current = num;//当前结点进行操
    int carry = 0;//进位数字
    while (l1 || l2 || carry)//只要有一方没有计算完，都需要再次生成新的结点 
    {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;//新结点的值
        carry = sum / 10;//下一个结点的加值
        current->next = initListNode();
        current = current->next;
        current->val = sum % 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    struct ListNode* temp = num;
    num = num->next;
    free(temp);
    return num;
}