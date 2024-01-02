#include <stdio.h>

#define NULL_PTR 0

/* 插入排序 */

#if 0
#define BUFFER_SIZE 7

int main()
{
    int arr[BUFFER_SIZE] = {1, 24, 30, 5, 58, 12, 39};

    int cpy = 0;

    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        cpy = arr[idx];

        for (int jdx = idx; jdx >= 0; jdx--)
        {
            if (arr[jdx - 1] > cpy)
            {
                arr[jdx] = arr[jdx - 1];
            }
            else
            {
                arr[jdx] = cpy;
                break;
            }
        }
    }

    for (int jdx = 0; jdx < BUFFER_SIZE; jdx++)
    {
        printf("%d\t", arr[jdx]);
    }
    printf("\n");
    

    return 0;
}

#else

/* 数组做函数参数会自动弱化成指针 */
int printArray(int *array, int arraySize)
{
    int ret = 0;

    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }

    return ret;
}

int insertSort01(int *array, int length)
{
    if(array == NULL)
    {
        return NULL_PTR;
    }

    int ret = 0;

    int cpy = 0;
    for (int pos = 0; pos < length; pos++)
    {
        cpy = array[pos];
        for (int idx = pos; idx >= 0; idx--)
        {
            if (cpy < array[idx - 1])
            {
                array[idx] = array[idx - 1];
            }
            else
            {
                array[idx] = cpy;
                break;
            }
        }
    }
    return ret;
}

int insertSort02(int *array, int length)
{
    if(array == NULL)
    {
        return NULL_PTR;
    }
    
    int ret = 0;

    int copyNum = 0;
    int cur = 0;
    for (int idx = 1; idx < length; idx++)
    {
        cur = idx;
        copyNum = array[idx];
        while (cur > 0 && copyNum < array[cur - 1])
        {
            array[cur] = array[cur - 1];
            cur--;
        } // 退出条件是: cur == 0 && copyNum >= array[cur - 1]
        array[cur] = copyNum;
    }

    return ret;
}

int main()
{
    int array[] = {24, 30, 4, 58, 12, 39};
    int length = sizeof(array) / sizeof(array[0]);

    // insertSort01(array, length);
    insertSort02(array, length);
    printArray(array, length);

    return 0;
}

#endif