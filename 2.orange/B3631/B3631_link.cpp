#include<stdio.h>
#include<stdlib.h>

typedef struct node//链表节点
{
    int data;
    struct node* next;
}node;

node* createnode(int i)//创建链表节点
{
    node* head=(node*)malloc(sizeof(node));
    head->data=i;
    head->next=NULL;
    return head;
}

node*find(node*pphead,int i)//查找数据为i的节点
{
    node*p=pphead;
    while(p!=NULL)
    {
        if(p->data==i) return p;
        p=p->next;
    }
    return NULL;
}

void pushback(node*before,int i)//在节点before后插入数据为i的节点
{
    node*p=createnode(i);
    p->next=before->next;
    before->next=p;
}

void delet(node*p)//删除节点p的下一个节点
{
    if(p->next==NULL)
        return;
    else if(p->next->next==NULL)
    {
        free(p->next);
        p->next=NULL;
    }
    else
    {
        node*q=p->next;
        p->next=p->next->next;
        free(q);
    }
}

// void print(node*head)//打印链表
// {
//     node*p=head;
//     while(p!=NULL)
//     {
//         printf("%d->",p->data);
//         p=p->next;
//     }
//     printf("NULL\n");
// }

int main()
{
    int n;scanf("%d",&n);
    node*phead=createnode(1);//创建头节点
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(x==1)
        {
            int a,b;scanf("%d%d",&a,&b);
            pushback(find(phead,a),b);
        }
        else if(x==2)
        {
            int a;scanf("%d",&a);
            node*p=find(phead,a);
            if(p->next==NULL)
            {
                printf("%d\n",0);
            }
            else
            {
                printf("%d\n",p->next->data);
            }
        }
        else if(x==3)
        {
            int a;scanf("%d",&a);
            delet(find(phead,a));
        }
    }
    //print(phead);
    return 0;
}