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
    quickSort(buffer, length);
    printArray(buffer, length);
    printf("\n");

    
    int val = 30;
    int isExist = binarySearchAppointValPos(buffer, length, val);
    printf("isExist:%d\n", isExist);

    return 0;
}