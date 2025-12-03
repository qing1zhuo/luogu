#include<stdio.h>
#include<stdlib.h>  
typedef struct node//节点结构体
{
    int data;
    struct node* next;  
}node;

node* createnode(int x)//创建节点
{
    node* p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}

void pushback(node**pphead,int x)//尾部插入节点
{
    if(*pphead==NULL)
    {
        *pphead=createnode(x);
        return;
    }
    else
    {
        node*p=*pphead;
        while(p->next!=NULL)
            p=p->next; 
        p->next=createnode(x);
        return;
    }
}

void print(node* p)//打印链表
{
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    printf("NULL\n");
}

node* tail(node* phead)//返回链表尾节点
{
    if(phead==NULL)
        return NULL;
    node* p=phead;
    while(p->next!=NULL)
        p=p->next;
    return p;
}


int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    node*phead=NULL;
    for (int i=1;i<=n;i++)
    {
        pushback(&phead,i);
    }
    tail(phead)->next=phead;//形成环
    while(phead!=NULL)
    {
        if(phead->next==phead)//链表中只剩一个节点
        {
            printf("%d\n",phead->data);
            phead=NULL;
        }
        else
        {
            for(int i=1;i<m-1;i++)
            {
                phead=phead->next;
            }//此时phead指向要删除的节点的前一个节点
            node* q=phead->next;//q指向要删除的节点
            printf("%d ",q->data);  
            phead->next=q->next;
            phead=q->next;
            free(q);
        }
    }
    return 0;
}