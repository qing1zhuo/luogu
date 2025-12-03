//AI生成

#include<stdio.h>
#include<stdlib.h>

// 定义链表节点结构
typedef struct node
{
    int data;
    struct node* next;
}node;

// 哈希表（数组）用于快速查找节点，存储节点指针
// 题目中数据范围是1到10^6，所以数组大小设为10^6+1足够
#define MAX_DATA 1000001
node* hash_table[MAX_DATA] = {NULL};

/**
 * 创建新节点并添加到哈希表
 * @param i 节点要存储的数据
 * @return 指向新创建节点的指针
 */
node* createnode(int i)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = i;
    new_node->next = NULL;
    // 将新节点添加到哈希表
    hash_table[i] = new_node;
    return new_node;
}

/**
 * 在指定节点后插入新节点
 * @param before 插入位置的前驱节点
 * @param i 新节点要存储的数据
 */
void pushback(node* before, int i)
{
    if (before == NULL) 
        return;  // 避免空指针访问
    
    node* p = createnode(i);
    // 插入到before节点之后
    p->next = before->next;
    before->next = p;
}

/**
 * 删除指定节点的下一个节点
 * @param p 要删除节点的前驱节点
 */
void delet(node* p)
{
    if (p == NULL || p->next == NULL)
        return;  // 无节点可删除
    
    node* q = p->next;  // 记录要删除的节点
    // 从哈希表中移除被删除的节点
    hash_table[q->data] = NULL;
    // 跳过被删除节点
    p->next = p->next->next;
    free(q);  // 释放内存
}

int main()
{
    int n;
    scanf("%d", &n);
    // 初始化链表，初始只有元素1，并添加到哈希表
    node* phead = createnode(1);
    
    for (int i = 0; i < n; i++)
    {
        int op;
        scanf("%d", &op);
        
        if (op == 1)  // 插入操作：1 x y 将y插入到x后面
        {
            int x, y;
            scanf("%d%d", &x, &y);
            // 直接从哈希表获取x对应的节点，O(1)时间
            node* found = hash_table[x];
            pushback(found, y);
        }
        else if (op == 2)  // 查询操作：2 x 输出x后面的元素
        {
            int x;
            scanf("%d", &x);
            // 直接从哈希表获取x对应的节点，O(1)时间
            node* found = hash_table[x];
            if (found == NULL || found->next == NULL)
                printf("0\n");
            else
                printf("%d\n", found->next->data);
        }
        else if (op == 3)  // 删除操作：3 x 删除x后面的元素
        {
            int x;
            scanf("%d", &x);
            // 直接从哈希表获取x对应的节点，O(1)时间
            node* found = hash_table[x];
            delet(found);
        }
    }
    
    // 释放链表内存
    node* curr = phead;
    while (curr != NULL)
    {
        node* next = curr->next;
        free(curr);
        curr = next;
    }
    
    return 0;
}
