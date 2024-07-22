/*
基于数组实现的栈
使用数组实现栈时，我们可以将数组的尾部作为栈顶。
入栈与出栈操作分别对应在数组尾部添加元素与删除元素
*/

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 10


/* 基于数组实现的栈 */
typedef struct ArrayStack
{
    int *data;
    int size;
}ArrayStack;


/* 构造函数 */
ArrayStack *createArrayStack()
{
    ArrayStack *stack = (ArrayStack *)malloc(sizeof(ArrayStack));

    //初始化一个大容量，避免扩容
    stack->data = (int *)malloc(sizeof(int) * MAX_SIZE);
    stack->size = 0;
    
    return stack;
}


/* 析构函数 */
void delArrayStack(ArrayStack *stack)
{
    free(stack->data);
    free(stack);
}


/* 获取栈的长度 */
int size(ArrayStack *stack)
{
    return stack->size;
}


/* 判断栈是否为空 */
bool isEmpty(ArrayStack *stack)
{
    return stack->size == 0;
}


/* 入栈 */
void push(ArrayStack *stack, int num)
{
    if(stack->size == MAX_SIZE)
        pritnf("栈已满\n");
    stack->data[stack->size] = num;
    stack->size++;
}


/* 访问栈顶元素 */
int peek(ArrayStack *stack)
{
    if(isEmpty(stack))
    {
        printf("栈为空\n");
        return INT_MAX;
    }
        
    return stack->data[stack->size - 1];
}


/* 出栈 */
int pop(ArrayStack *stack)
{
    int val = peek(stack);
    stack->size--;
    return val;
}





