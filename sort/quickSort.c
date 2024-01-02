#include <stdio.h>

#define NULL_PTR 0

/* 快速排序 */
/* 时间复杂度是O(NlogN) */
/* 算法：找第一个元素作为基准值   <=base  base  >=base
        右边：当遍历到的元素比基准值要小的时候 将元素覆盖start的位置
             当遍历到的元素比基准值要大的时候 end向前移动
        左边：当遍历到的元素比基准值要大的时候 将元素覆盖到end的位置
             当遍历到的元素比基准值要小的时候 start向后移动 */


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
    } //退出条件：start = end

    array[start] = baseValPos;

    return start;
}

int quickSort(int *array, int start, int end)
{
    if(array == NULL)
    {
        return NULL_PTR;
    }

    int ret = 0;

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



int main()
{
    int array[] = {17, 13, 29, 39, 19, 30, 34, 18, 33, 15};
    int length = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, length);
    printArray(array, length);
    return 0;
}