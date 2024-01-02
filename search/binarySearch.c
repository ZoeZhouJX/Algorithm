#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10


int printArray(int *array, int length)
{
    int ret = 0;
    if (array == NULL)
    {
        return ret;
    }

    for (int idx = 0; idx < length; idx++)
    {
        printf("%d\t", array[idx]);
    }

    return ret;
}

static int findBaseValPos(int *array, int start, int end)
{
    int ret = 0;

    end--;

    /* 基准值 */
    int baseValPos = array[start];
    while (start < end)
    {
        while (start < end)
        {
            if (array[end] < baseValPos)
            {
                array[start] = array[end];
                start++;
                break;
            }
            else
            {
                end--;
            }
        }

        while (start < end)
        {
            if (array[start] > baseValPos)
            {
                array[end] = array[start];
                end--;
                break;
            }
            else
            {
                start++;
            }
        }
    } // 退出条件：start = end

    array[start] = baseValPos;

    return start;
}

int quickSort(int *array, int start, int end)
{
    int ret = 0;
    if (array == NULL)
    {
        return ret;
    }

    /* 递归 必须考虑结束条件
       如果strat == end 说明数组只有一个元素 直接返回 */
    if (start >= end)
    {
        return ret;
    }

    int baseValPos = findBaseValPos(array, start, end);
    /* 对基准值左边排序 */
    quickSort(array, start, baseValPos);
    /* 对基准值右边排序 */
    quickSort(array, baseValPos + 1, end);

    return ret;
}

/* 返回值：1表示存在 0表示不存在 */
int binarySearchAppointValPos(int *array, int length, int val)
{
    if (array == NULL)
    {
        return 0;
    }

    int start = 0;
    int end = length - 1;
    int mid = 0;

    while (start <= end)
    {
        mid = (start + end) >> 1;
        /* 找到了 */
        if (array[mid] == val)
        {
            return mid;
        }
        else if (array[mid] < val)
        {
            start = mid + 1;
        }
        else if (array[mid] > val)
        {
            end = mid - 1;
        }
    } 
    /* 没找到 */
    return -1;   
}

int main()
{
    int buffer[BUFFER_SIZE] = {0};

    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        buffer[idx] = rand() % 100 + 1;
    }

    int length = sizeof(buffer) / sizeof(buffer[0]);
    quickSort(buffer, 0, length);
    printArray(buffer, length);
    printf("\n");

    
    int val = 22;
    int isExist = binarySearchAppointValPos(buffer, length, val);
    printf("isExist:%d\n", isExist);

    return 0;
}