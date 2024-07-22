/*
基于链表的实现
将链表的“头节点”和“尾节点”分别视为“队首”和“队尾”，规定队尾仅可添加节点，队尾仅可删除节点。
*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/* 初始化链表 */
typedef struct ListNode
{
    int val;
    struct ListNode *next;

}ListNode,*LNode;


/* 基于链表实现的队列 */
typedef struct LinkedListQueue
{
    struct ListNode *front, *rear;
    int queSize;
}LinkedListQueue;


/* 初始化链表 */
ListNode *CreateList(int val)
{
    ListNode *node;
    node = (LNode)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
}


/* 构造函数 */
LinkedListQueue *createLinkedListQueue()
{
    LinkedListQueue *queue = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->queSize = 0;
    return queue;
}


/* 析构函数 */
void delLinkedListQueue(LinkedListQueue *queue)
{
    while(queue->front != NULL)
    {
        ListNode *tmp = queue->front;
        queue->front = queue->front->next;
        free(tmp);
    }
}


/* 获取队列的长度 */
int size(LinkedListQueue *queue)
{
    return queue->queSize;
}


/* 判断队列是否为空 */
bool isEmpty(LinkedListQueue *queue)
{
    return size(queue) == 0;
}


/* 入队 */
void push(LinkedListQueue *queue, int num)
{
    ListNode *node = (LNode)malloc(sizeof(ListNode));
    node = CreateList(num);
    if(queue->front == NULL)
    {
        queue->front = node;
        queue->rear = node;
    }
    else
    {
        queue->rear->next= node;
        queue->rear = node;
    
    }
    queue->queSize++;

}


/* 访问队首元素 */
int peek(LinkedListQueue *queue)
{
    if(queue != NULL)
        return;
    return queue->front->val;
}


/* 出队 */
int pop(LinkedListQueue *queue)
{
    int val = peek(queue);
    ListNode *tmp = queue->front;
    queue->front = queue->front->next;
    free(tmp);
    queue->queSize--;
    return val;
}



