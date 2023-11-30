#include <stdio.h>
#include<stdlib.h>
#include <assert.h>

struct Node
{
    int data;
    struct Node*next;
};

struct Node* creatlist()
{
    struct Node *headnode=(struct Node*)malloc(sizeof(struct Node));
    headnode->data = 0;
    headnode->next=NULL;
    return headnode;
}

struct Node * creatnode(int data)
{
    struct Node*newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next=NULL;
    return newnode;
}

void print(struct Node *headnode)
{
    struct Node *Pmove=headnode->next;
    while(Pmove)
    {
        printf("%d\n",Pmove->data);
        Pmove=Pmove->next;
    } 
    printf("\n");
}

void insertnode1(struct Node*headnode,int data)//头插法。
{
    struct Node*newnode=creatnode(data);
    newnode->next=headnode->next;
    headnode->next=newnode;
}

void insertnode2(struct Node*headnode,int data)
{
    struct Node *last=headnode->next;
    while(last->next)
    {
        last=last->next;
    }
    struct Node * lastnode=creatnode(data);
    last->next=lastnode;
    lastnode->next=NULL;
}

int delenode(struct Node*headnode,int data)
{
    struct Node *frontNode=headnode->next;
    struct Node *beforeNoe=headnode;
    assert(frontNode !=NULL);
    while (frontNode ->data!=data)
    {
        beforeNoe = frontNode;
        frontNode=beforeNoe->next;
        if(frontNode==NULL)
        {
            //printf("无法删除\n");
            return  0;
        }
    }
    beforeNoe->next=frontNode->next;
    free(frontNode);
    return 1;
}

int main()
{
    struct Node*list=creatlist();
    insertnode1(list,2);
    insertnode1(list,3);
    insertnode1(list,4);
    insertnode1(list,2);
    insertnode1(list,2);
    insertnode2(list,1);
    insertnode2(list,2);
    print(list);
    int flag=0;
    do
    {
        flag=delenode(list,2);
    } while (flag);
    print(list);
    return  0;
}