/*
    作业要求：
        1.用指定参数
        2.返回值为int*型
        3.用malloc()函数
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int *mergeOderNum(int *num1, int num1Size, int *num2, int num2Size, int *newNumSize)
{

    /* 计算合并后数组的大小为num1Size + num2Size */
    *newNumSize = num1Size + num2Size;

    /* 为目标数组分配空间，并初始化为0 */
    int *newNum = (int *)malloc((*newNumSize) * sizeof(int));
    memset(newNum, 0, (*newNumSize) * sizeof(int));

    /* 数组元素复制 */
    int idx1 = 0;
    int idx2 = 0;
    int idx3 = 0;
    while (idx1 < num1Size && idx2 < num2Size)
    {
        if (num1[idx1] <= num2[idx2])
        {
            newNum[idx3] = num1[idx1];
            idx1++;
        }
        else
        {
            newNum[idx3] = num2[idx2];
            idx2++;
        }
        idx3++;
    }

    /* 通过判断idx与numSize的大小来判断哪个数组先把所有的数给完 */
    /* 将有多余元素剩下的数组中的数给newNum */
    /* 这里用if else是没问题的，但是用两个while更加的易懂，也更符合while循环逻辑 */
    while (idx3 < *newNumSize)
    {
        while (idx1 < num1Size)
        {
            newNum[idx3] = num1[idx1];
            idx1++;
            idx3++;
        }
        while (idx2 < num2Size)
        {
            newNum[idx3] = num2[idx2];
            idx2++;
            idx3++;
        }
    }

    return newNum;
}

/* 用于下面的排序函数 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* 之前选择排序的排序函数 */
void sort(int arr[], int size)
{
    for (int idx1 = 0; idx1 < size - 1; idx1++)
    {
        int minIdx = idx1;
        for (int idx2 = idx1 + 1; idx2 < size; idx2++)
        {
            if (arr[idx2] < arr[minIdx])
            {
                minIdx = idx2;
            }
        }
        swap(&arr[minIdx], &arr[idx1]);
    }
}

int main()
{
    srand(time(NULL));

    /* 生成两个数组元素个数随机、数组元素大小1到20的随机的数组 */
    int num1Size = rand() % 10 + 1;
    int num2Size = rand() % 10 + 1;

    int *num1 = (int *)malloc(num1Size * sizeof(int));
    memset(num1, 0, num1Size * sizeof(int));
    int *num2 = (int *)malloc(num2Size * sizeof(int));
    memset(num2, 0, num2Size * sizeof(int));
    /* 对两个数组赋予大小为1到20内的随机数 */
    for (int idx = 0; idx < num1Size; idx++)
    {
        num1[idx] = rand() % 20 + 1;
    }

    /* 对数组num1排序 */
    sort(num1, num1Size);

    for (int idx = 0; idx < num2Size; idx++)
    {
        num2[idx] = rand() % 20 + 1;
    }

    /* 对数组num2排序 */
    sort(num2, num2Size);

    /* 打印出两个数组的数 */
    printf("数组一有%d个数: \n", num1Size);
    for (int idx = 0; idx < num1Size; idx++)
    {
        printf("%d ", num1[idx]);
    }

    printf("\n");

    printf("数组二有%d个数: \n", num2Size);
    for (int idx = 0; idx < num2Size; idx++)
    {
        printf("%d ", num2[idx]);
    }

    printf("\n");

    int newNumSize = 0;

    int *newNum = mergeOderNum(num1, num1Size, num2, num2Size, &newNumSize);

    /* 打印出得到的数组 */
    printf("合并后得到的数组为%d个数:\n", newNumSize);

    for (int idx = 0; idx < newNumSize; idx++)
    {
        printf("%d ", newNum[idx]);
    }

    printf("\n");

    /* 释放内存 */
    if (num1 != NULL && num2 != NULL && newNum != NULL)
    {
        free(num1);
        free(num2);
        free(newNum);
        num1 = NULL;
        num2 = NULL;
        newNum = NULL;
    }

    return 0;
}
