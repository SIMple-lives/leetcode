 #include<stdio.h>
 #include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node * creatnode(struct Node *head,int new_data)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->next=NULL;
    return new_node;
}

void insert(struct Node * head, int new_data)
{
    struct Node *new_node=creatnode(head,new_data);
    new_node->next=head->next;
    head->next=new_node;
}

void printlist(struct Node *head)
{
    struct Node *Pmove=head->next;
    while(Pmove!=NULL)
    {
        printf("%d\n",Pmove->data);
        Pmove=Pmove->next;
    }
}

struct ListNode* swapPairs1(struct ListNode* head){
    //使用双指针避免使用中间变量
    typedef struct Node ListNode;
    ListNode *fakehead = (ListNode *)malloc(sizeof(ListNode));
    fakehead->next = head;
    ListNode* right = fakehead->next;
    ListNode* left = fakehead;
    while(left && right && right->next ){
        left->next = right->next;
        right->next = left->next->next;
        left->next->next = right;
        left = right;
        right = left->next;
    }
    return fakehead->next;
}

struct Node* swapPairs2(struct ListNode* head) //Leetcode 上的题没有虚拟头结点，即首元素即为链表的头部结点.
{
    struct Node *fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        struct Node *node1=fast->next;
        struct Node *node2=fast->next->next;
        fast->next=node2;
        node1->next=node2->next;
        node2->next=node1;
        fast=node1;
    }
    return head;
}

int main()
{
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    head->next=NULL;
    insert(head,10);
    insert(head,20); 
    insert(head,30);
    insert(head,40);
    printlist(head);
    struct Node *new_head=swapPairs(head);
    printlist(new_head); 
    return 0;
}