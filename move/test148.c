#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

int partition(int num[],int i,int j)
{
    int x=num[i];
    while(i<j)
    {
        while(i<j && num[j]>x)
        {
            j--;
        }
        if(i<j)
        {
            num[i]=num[j];
            i++;
        }
        while(i<j &&num[i]<x)
        {
            i++;
        }
        if(i<j)
        {
            num[j]=num[i];
            j--;
        }
    }
    num[i]=x;
    return i;
}

void quicksort(int num[],int i,int j)
{
    if(i<j)
    {
        int index=partition(num,i,j);
        quicksort(num,i,index-1);
        quicksort(num,index+1,j);
    }
}

struct ListNode* sortList(struct ListNode* head) //先挂到数组上，拍完序生成赋值
{
    struct ListNode *cur=head;
    int len=0;
    while(cur)
    {
        len++;
        cur=cur->next;
    }
    cur=head;
    int *num=(int *)malloc(sizeof(int)*len);
    for(int i=0;i<len;i++)
    {
        num[i]=cur->val;
        cur=cur->next;
    }
    cur=head;
    int index=0;
    quicksort(num,0,len-1);
    while(cur)
    {
        cur->val=num[index];
        index++;
        cur=cur->next;
    }
    return head;
}


/* int cmp(const void *a, const void *b) {
    return (*(int *)a -*(int *)b);
}


struct ListNode* sortList(struct ListNode* head) 
{
    struct ListNode *cur=head;
    int len=0;
    while(cur)
    {
        len++;
        cur=cur->next;
    }
    cur=head;
    int *num=(int *)malloc(sizeof(int)*len);
    for(int i=0;i<len;i++)
    {
        num[i]=cur->val;
        cur=cur->next;
    }
    cur=head;
    int index=0;
    qsort(num,len,sizeof(int),cmp);
    while(cur)
    {
        cur->val=num[index];
        index++;
        cur=cur->next;
    }
    return head;
}
 */