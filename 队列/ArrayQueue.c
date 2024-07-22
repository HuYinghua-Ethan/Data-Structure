/*
基于数组实现队列
在数组中删除首元素的时间复杂度为 ，这会导致出队操作效率较低。
可以采用以下巧妙方法来避免这个问题：
可以使用一个变量 front 指向队首元素的索引，并维护一个变量 size 用于记录队列长度
定义 rear = front + size,这个公式计算出来的 rear 指向队尾元素之后的下一个位置。

基于此设计，数组中包含元素的有效区间为 [front, rear - 1]
入队操作：将输入元素赋值给 rear 索引处，并将 size 增加1
出队操作：只需将 front 增加1，并将 size 减少1

但是，这种设计存在一个问题：
在不断出队和入队的过程中， front 和 rear 都在向右移动，当它们到达数组尾部时就无法继续移动了。
为了解决这个问题， 我们可以将数组视为首尾相接的“环形数组”。
对于环形数组，我们需要让 front 和 rear 在越过数组尾部时，直接回到数组头部继续遍历。这种周期性规律可以通过“取余操作”来实现。
*/


#include <stdio.h>
#include <stdbool.h>

typedef struct ArrayQueue
{
    int *nums;           //用于存储队列元素的数组
    int front;          //队首指针，指向队首元素
    int queSize;        //尾指针，指向队尾+1
    int queCapacity;    //队列容量
}ArrayQueue;


/* 构造函数 */
ArrayQueue *createArrayQueue(int capacity)
{
    ArrayQueue *queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
    queue->nums = (int *)malloc(capacity * sizeof(int));
    queue->queCapacity = capacity;;
    queue->front = queue->queSize = 0;
    return queue;
}


/* 析构函数 */
void delArrayQueue(ArrayQueue *queue)
{
    free(queue->nums);
    free(queue);

}


/* 获取队列的容量 */
int Capacity(ArrayQueue *queue)
{
    return queue->queCapacity;
}


/* 获取队列长度 */
int Size(ArrayQueue *queue)
{
    return queue->queSize;
}


/* 判断队列是否为空 */
bool isEmpty(ArrayQueue *queue)
{
    return queue->queSize == 0;
}


/* 访问队首元素*/
int peek(ArrayQueue *queue)
{
    if(queue == NULL)
        return;
    return queue->nums[queue->front];
}


/* 入队 */
void push(ArrayQueue *queue, int num)
{
    if(Size(queue) == Capacity(queue))
    {
        printf("队列已满\n");
        return;
    }

    //计算队尾指针，指向队尾索引
    //通过取余操作实现 rear 越过数组尾部后回到头部
    int rear = (queue->front + queue->queSize) % queue->queCapacity;
    queue->nums[rear] = num;
    queue->queSize++; 
}


/* 出队 */
int pop(ArrayQueue *queue)
{
    int val = peek(queue);
    queue->front = (queue->front + 1) % queue->queCapacity;
    queue->queSize--;
    return val;
}

