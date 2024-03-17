#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MyQueue
{
    int data;
    struct MyQueue*next;

}MyQueue;

MyQueue* myQueueCreate() 
{
    MyQueue *Queue=(MyQueue *)malloc(sizeof(MyQueue));
    Queue->data=0;
    Queue->next=NULL;
    return Queue;
}

void myQueuePush(MyQueue* obj, int x) 
{
    MyQueue*Q=(MyQueue*)malloc(sizeof(MyQueue));
    Q->data=x;
    while(obj->next)
    {
        obj=obj->next;
    } 
    obj->next=Q;
    Q->next=NULL;
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->next==NULL)
    {
        return true;
    }
    return false;
}

int myQueuePop(MyQueue* obj) 
{
    if(myQueueEmpty(obj))
    {
        return -1;
    } 
    MyQueue *Q=obj->next;
    obj->next=Q->next;
    int data=Q->data;
    free(Q);
    return data;
}

int myQueuePeek(MyQueue * obj) 
{
    if(obj->next)
    {
        return obj->next->data;
    }
    return -1;
}



void myQueueFree(MyQueue* obj) 
{
    while(obj)
    {
        MyQueue *tmp=obj;
        obj=obj->next;
        free(tmp);
    }    
}

int main()
{
    MyQueue *Q=myQueueCreate();
    myQueuePush(Q,1);
    myQueuePush(Q,2);
    int num=myQueuePeek(Q);
    printf("\033[31m%d\n",num);
    num=myQueuePop(Q);
    printf("\033[31m%d\n",num);
    myQueueFree(Q);
    return 0;
}