/* 
链表：链表的设计使得各个节点可以分散到内存各处，它们的内存地址无须连续。
链表的组成单位是节点。
每个节点都包含两项数据：节点的“值”和指向下一节点的“引用”。
1.链表的首个节点被称为“头节点”，最后一个节点被称为“尾节点”。
2.尾节点指向的是“空”。
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/* 初始化链表 */
typedef struct ListNode
{
    int val;
    struct ListNode *next;

}ListNode,*LNode;


/* 初始化链表 */
LNode CreateList(int val)
{
    LNode node;
    node = (LNode)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
}


// /* 双向链表*/
// typedef struct ListNode
// {
//     int val;                //节点值
//     struct ListNode *next;  //指向节点之后的指针
//     struct ListNode *prev;  //指向前驱节点的指针
// }ListNode;

// /* 构造函数 */
// ListNode *DoubleListNode(int val)
// {
//     ListNode *node;
//     node = (ListNode *)malloc(sizeof(ListNode));
//     node->val = val;
//     node->next = NULL;
//     node->prev = NULL;
//     return node;
// }



/* 插入节点   只需改变两个节点引用指针即可*/
// 在链表的节点n0之后插入节点P
void Insert(LNode n0, LNode P)
{   
    LNode n1 = n0->next;
    P->next = n1;
    n0->next = P;

}


/* 删除节点 */
void Delete(LNode n0)
{
    if(n0->next == NULL)
        return;
    
    // n0 -> P -> n1
    LNode P = n0->next;
    LNode n1 = P->next;;
    n0->next = n1;
    free(P);  //释放内存
}


/* 访问节点 */
//需要从头节点中出发，逐个向后遍历
LNode Access(LNode n0, int index)
{
    if(n0 == NULL)
        return NULL;
    for(int i = 0; i < index; i++)
    {
        n0 = n0->next;
    }
    return n0;
}


/* 查找节点 */
int Find(LNode head, int target)
{
    int index = 0;
    while(head)
    {
        if(head->val == target)
            return  index;
        head = head->next;
        index++;
    }
}


int main()
{
    /* 初始化各个节点*/
    LNode n0, n1, n2, n3, n4;
    LNode node;
    int index;
    /* 初始化链表 */
    n0 = CreateList(1);
    n1 = CreateList(3);
    n2 = CreateList(2);
    n3 = CreateList(5);
    n4 = CreateList(4);
    /* 构建节点之间的引用 */
    n0->next = n1;
    n1->next = n2;
    n2->next = n3; 
    n3->next = n4;

    // 访问节点
    node =Access(n0, 3);
    printf("第三个节点的值未: %d\n", node->val);

    // 查找节点
    index = Find(n0, 5);
    printf("值为5的是第%d个节点\n", index);

    return 0;
}


