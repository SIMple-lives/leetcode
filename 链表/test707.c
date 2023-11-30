#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct 
{
    int val;
    struct MyLinkedLisr*next;
} MyLinkedList;

MyLinkedList * creatnode(int data)
{
    MyLinkedList *newnode=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    newnode->next=NULL;
    newnode->val=data;
    return newnode;
}

MyLinkedList* myLinkedListCreate() //设置头结点.
{
    MyLinkedList * headnode =(MyLinkedList*)malloc(sizeof(MyLinkedList));
    headnode->next=NULL;
    return headnode;
}

int myLinkedListGet(MyLinkedList* obj, int index) 
{
    int num=0;
    MyLinkedList*findnode=obj->next;
    while(findnode!=NULL)
    {
        if(num==index)
        {
            return findnode->val;
        }
        num+=1;
        findnode=findnode->next;
    }
    return -1;
}



void myLinkedListAddAtHead(MyLinkedList* obj, int val) 
{
    MyLinkedList *newnode=creatnode(val);
    newnode->next=obj->next;
    obj->next=newnode;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) 
{
    MyLinkedList *newnode=creatnode(val);
    MyLinkedList *last=obj;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=newnode;
    newnode->next=NULL;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) 
{
    MyLinkedList *insertnode = obj;
    for (int i = 0; insertnode != NULL; i++)
    {
        if (i == index - 1)
        {
            MyLinkedList *newnode = creatnode(val);
            newnode->next = insertnode->next;
            insertnode->next = newnode;
            return;
        }
        else
        {
            insertnode = insertnode->next;
        }
    }
}


/* void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) 
{
    MyLinkedList *insertnode=obj->next;
    if(index ==0)
    {
        myLinkedListAddAtHead(obj,val);
        return ;
    }
    for(int i=1; insertnode!=NULL;i++)
    {
        if(i==index)
        {
            MyLinkedList *newnode=creatnode(val);
            newnode->next=insertnode->next;
            insertnode->next=newnode;
            return  ;
        }
        else
        {
            insertnode=insertnode->next;
        }
    }
} */

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) 
{
    MyLinkedList *deletenode=obj->next;
    int num=0;
    while(deletenode!=NULL&&num<index)
    {
        if(deletenode->next!=NULL&&num+1==index)
        {
            MyLinkedList *temp=deletenode->next;
            deletenode->next=temp->next;
            free(temp);
            return ;
        }
        else
        {
            deletenode=deletenode->next;
            num++;
        }
    }
}

void myLinkedListFree(MyLinkedList* obj) 
{
    while(obj != NULL)
    {
        MyLinkedList *tmp = obj;
        obj = obj->next;
        free(tmp);
    }
}

int main()
{

    return 0;
}