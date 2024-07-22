/*
基于链表实现栈
对于入栈操作，我们只需将元素插入链表头部，这种节点插入方法被称为“头插法”。
而对于出栈操作，只需将头节点从链表中删除即可。
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<limits.h>


/* 初始化链表 */
typedef struct ListNode
{
    int val;
    struct ListNode *next;

}ListNode,*LNode;


/* 基于链表实现的栈*/
typedef struct LinkedListStack
{
    int size;  //栈的长度
    struct ListNode *top;  //将头节点作为栈顶
}LinkedListStack;


/* 构造函数 */
LinkedListStack *createLinkedListStack()
{
    LinkedListStack *s = (LinkedListStack *)malloc(sizeof(LinkedListStack));
    s->size = 0;
    s->top = NULL;
    return s;
}


/* 析构函数 */
void delLinkedListStack(LinkedListStack *s)
{
    while(s->top)
    {
        LinkedListStack *n = s->top->next;
        free(s->top);
        s->top = n;
    }
    free(s);
}


/* 获取栈的长度*/
int size(LinkedListStack *s)
{
    return s->size;
}


/* 判断栈是否为空*/
bool isEmpty(LinkedListStack *s)
{
    return s->size == 0;
}


/* 入栈 */
void push(LinkedListStack *s, int num)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->next = s->top;
    node->val = num;
    s->top = node;
    s->size++;
}


/* 访问栈顶元素 */
int peek(LinkedListStack *s)
{
    if(s->size == 0)
    {
        printf("栈为空\n");
        return INT_MAX;
    }
    return s->top->val;
}


/* 出栈 */
int pop(LinkedListStack *s)
{
    int val = peek(s);
    ListNode *tmp = s->top;
    s->top = s->top->next;
    free(tmp);
    s->size--;
    return val;
}

