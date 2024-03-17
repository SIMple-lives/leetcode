#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode *next;
}ListNode;

typedef struct data
{
    int mode;
    int x;
    int y;
}data;

ListNode * init()
{
    ListNode *L=(ListNode *)malloc(sizeof(ListNode));
    L->data=1;
    L->next=NULL;
    return L;
}

void insert(ListNode* L, int x, int y) {
    while (L) {
        if (L->data == x) {
            ListNode* node = (ListNode*)malloc(sizeof(ListNode));
            node->data = y;
            node->next = L->next;
            L->next = node;
            break;  // Add a break to exit the loop after inserting the node
        } else {
            L = L->next;
        }
    }
}

int ask(ListNode* L, int x) {
    while (L) {
        if (L->data == x) {
            int num = 0;
            if (L->next != NULL) {
                num = L->next->data;
            }
            return num;
        } else {
            L = L->next;
        }
    }
    return 0;  
}

void delete(ListNode* L, int x) 
{
    while (L) 
    {
        if (L->data == x && L->next != NULL) 
        {
            ListNode* next = L->next;
            L->next = L->next->next;
            free(next);
            return;
        }
        L = L->next;
    }
}

void dothing(data *arr,int n,ListNode *L)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i].mode==1)
        {
            insert(L,arr[i].x,arr[i].y);
        }
        if(arr[i].mode==2)
        {
            int num=ask(L,arr[i].x);
            printf("%d\n",num);
        }
        if(arr[i].mode==3)
        {
            delete(L,arr[i].x);
        }
    }
}

void dofree(ListNode *L)
{
    while(L)
    {
        ListNode *cur=L;
        L=L->next;
        free(cur);
    }
}

int main()
{
    data arr[1000];
    ListNode *L=init();
    int n=0;
    scanf("%d ",&n);
    for(int i=0;i<n;i++)
    {
        int mode;
        scanf("%d",&mode);
        arr[i].mode=mode;
        scanf("%d",&arr[i].x);
        if(mode==1)
        {
            scanf("%d",&arr[i].y);
        }
    }
    dothing(arr,n,L);
    dofree(L);
    return 0;
}