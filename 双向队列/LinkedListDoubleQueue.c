/*
基于双向链表的实现
对于双向队列而言，头部和尾部都可以执行入队和出队操作。
换句话说，双向队列需要实现另一个对称方向的操作。
将双向链表的头节点和尾节点视为双向队列的队首和队尾，同时实现在两端添加和删除节点的功能。
*/

#include <stdio.h>
#include <stdbool.h>

/* 双向链表节点 */
typedef struct DoublyListNode
{
    int val;                        //节点值
    struct DoublyListNode *next;    //后继节点
    struct DoublyListNode *prev;    //前驱节点
}DoublyListNode;


/* 构造函数 */
DoublyListNode* createDoublyListNode(int num)
{
    DoublyListNode *node = (DoublyListNode*)malloc(sizeof(DoublyListNode));
    node->val = num;
    node->next = NULL;
    node->prev = NULL;
    return node;
}


/* 析构函数 */
void delDoublyListNode(DoublyListNode *node)
{
    free(node);
}


/* 基于双向链表实现的双向队列 */
typedef struct LinkedListDeque
{
    DoublyListNode *front,*rear; //头节点 front，尾节点 rear
    int queSize;;                //双向队列的长度
}LinkedListDeque;


/* 构造函数 */
LinkedListDeque *createLinkedListDeque()
{
    LinkedListDeque *deque = (LinkedListDeque*)malloc(sizeof(LinkedListDeque));
    deque->front = NULL;
    deque->rear = NULL;
    deque->queSize = 0;
    return deque;
}


/* 析构函数 */
void delLinkedListDeque(LinkedListDeque *deque)
{
    // 释放所有的节点
    for(int i = 0; i < deque->queSize; i++)
    {
        DoublyListNode *node = deque->front;
        deque->front = deque->front->next;
        free(node);
    }
    free(deque);
}


/* 获取队列的长度 */
int Size(LinkedListDeque *deque)
{
    return deque->queSize;
}


/* 判断队列是否为空 */
bool isEmpty(LinkedListDeque *deque)
{
    return deque->queSize == 0;
}


/* 入队 */
void push(LinkedListDeque *deque, int num, bool isFront)
{
    DoublyListNode *node = createDoublyListNode(num);
    // 若链表为空，则令 front 和 rear 指向 node
    if(isEmpty(deque))
    {
        deque->front = deque->rear = node;
    }
    else if(isFront)  //队首入队
    {
        deque->front->prev = node;
        node->next = deque->front;
        deque->front = node;
    }
    else  //队尾入队
    {
        deque->rear->next = node;
        node->prev = deque->rear;
        deque->rear = node;
    }
    deque->queSize++;

}


/* 队首入队 */
void pushFirst(LinkedListDeque *deque, int num)
{
    push(deque, num, true);
}


/* 队尾入队 */
void pushLast(LinkedListDeque *deque, int num)
{
    push(deque, num, false);
}


/* 访问队首元素 */
int peekFirst(LinkedListDeque *deque)
{
    return deque->front->val;
}


/* 访问队尾元素 */
int peekLast(LinkedListDeque *deque)
{
    return deque->rear->val;
}


int pop(LinkedListDeque *deque, bool isFront)
{
    if(isEmpty(deque))
    {
        printf("队列为空，不能出队\n");
        return -1;
    }

    int val;
    if(isFront)   //队首出队
    {
        val = peekFirst(deque);
        DoublyListNode *fNext = deque->front->next;
        if(fNext)
        {
            fNext->prev = NULL;
            deque->front->next = NULL;
            
        }
        delDoublyListNode(deque->front);
        deque->front = fNext;  //更新头节点

    }    
    else  //队尾出队
    {
        val = peekLast(deque);
        DoublyListNode *rPrev = deque->rear->prev;
        if(rPrev)
        {
            rPrev->next = NULL;
            deque->rear->prev = NULL;
        }
        delDoublyListNode(deque->rear);
        deque->rear = rPrev;  //更新尾节点
    }
    deque->queSize--;
    return val;
}


/* 队首出队 */
int popFirst(LinkedListDeque *deque)
{
    return pop(deque, true);
}


/* 队尾出队 */
int popLast(LinkedListDeque *deque)
{
    return pop(deque, false);
}


