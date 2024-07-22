/*
数组：
数组是一种线性数据结构，将其相同类型的元素存储在连续的内存空间中。
我们将元素在数组中的位置称为该元素的索引。
*/

#include <stdio.h>
#include <string.h>

/* 访问元素 */
/* 数组元素被存储在连续的内存空间中，这意味着计算数组元素的内存地址非常容易 */
/* 元素内存地址 = 数组首地址 + 索引 * 元素大小 */
void Acess(int arr[], int index)
{
    printf("The element at index %d is %d\n", index, arr[index]);
}


/* 插入元素 */
/* 由于数组的长度是固定的，因此插入一个元素必定会导致数组尾部元素“丢失” */
void Insert(int arr[], int len, int index, int num)
{
    int i;
    /*
    len = sizeof(arr) / sizeof(arr[0]);
    当数组作为函数参数传递时，它会被转换为指向数组第一个元素的指针。
    这意味着 len 的值将不正确，可能导致数组越界访问或其他未定义行为。
    为了修复这个问题，数组的长度应该在函数调用时作为参数传递进来。
    */ 
    // 把索引 index 以及之后的所有元素向后移动一位
    for(i = len - 1; i > index; i--)
    {
        arr[i] = arr[i-1];
    }
    // 将 num 赋给 index 处的元素
    arr[index] = num;
    
}


/* 删除元素 */
/*若想删除索引 index 处的元素，则需要把索引 index 之后的元素都向前移动一位。*/
/* 删除元素完成后，原先末尾的元素变得“无意义”了，所以我们无须特意去修改它。*/
void Delete(int arr[], int len, int index)
{
    int i;
    // 把索引 index 之后的所有元素向前移动一位
    for(i = index; i < len - 1; i++)
    {
        arr[i] = arr[i+1];
    }
}

/* 遍历数组 */
void Travers(int *arr, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}


/* 查找元素 */
/* 在数组中查找指定元素需要遍历数组，每轮判断元素值是否匹配，若匹配则输出对应索引。*/
/* 因为数组是线性数据结构，所以上述查找操作被称为“线性查找”。 */
int Find(int *arr, int len, int target)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    int arr[5] = {1, 3, 2, 5, 4};
    int len = 0;
    len = sizeof(arr) / sizeof(arr[0]);

    Acess(arr, 3);

    Insert(arr, len, 2, 8);
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);

    printf("\n");

    Delete(arr, len, 2);
    len = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);

    return 0;
}


