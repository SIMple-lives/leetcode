#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MyStack
{
    int data;
    struct MyStack *next;    
} MyStack;


MyStack* myStackCreate() 
{
    MyStack *S=(MyStack *)malloc(sizeof(MyStack));
    S->next=NULL;
    S->data=0;   
    return S; 
}

void myStackPush(MyStack* obj, int x) 
{
    MyStack*node=(MyStack *)malloc(sizeof(MyStack));
    node->data=x;
    node->next=obj->next;
    obj->next=node;    
}

bool myStackEmpty(MyStack* obj) 
{
    if(obj->next==NULL)
    {
        return true;
    }    
    return false;
}

int myStackPop(MyStack* obj) 
{
    if(myStackEmpty(obj))
    {
        return -1;
    }
    else
    {
        MyStack *node=obj->next;
        obj->next=node->next;
        int data=node->data;
        return data;
    }
}

int myStackTop(MyStack* obj) 
{
    if(obj->next)
    {
        return obj->next->data;
    }
    return -1;
}

void myStackFree(MyStack* obj) 
{
    while(obj)
    {
        MyStack *node=obj;
        obj=obj->next;
        free(node);
    }
}