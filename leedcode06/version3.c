#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE2 8
#define BUFFER_SIZE3 5

int *mergeOrderNums(int *num1, int num1size, int *num2, int num2size, int *newNumSize)
{

    int pos1 = 0;
    int pos2 = 0;
    int pos3 = 0;
    *newNumSize = num1size + num2size;
    int *newNum = (int *)malloc(sizeof(int) * *newNumSize);

    while (pos1 < num1size && pos2 < num2size)
    {

        if (num1[pos1] < num2[pos2])
        {
            newNum[pos3] = num1[pos1];
            pos3++;
            pos1++;
        }
        else
        {
            newNum[pos3] = num2[pos2];
            pos3++;
            pos2++;
        }
    }

    while (pos3 < (num1size + num2size))
    {
        if (pos1 < num1size)
        {

            newNum[pos3] = num1[pos1];
            pos3++;
            pos1++;
        }
        else
        {
            newNum[pos3] = num2[pos2];
            pos3++;
            pos2++;
        }
    }
    return newNum;
}

int main()
{
    int array1[BUFFER_SIZE2] = {1, 1, 2, 3, 3, 5, 7, 19};
    int array2[BUFFER_SIZE3] = {2, 7, 9, 12, 17};
    int *newNumSize = NULL;
    newNumSize = (int *)malloc(sizeof(int));
    int *newNum = NULL;
    newNum = mergeOrderNums(array1, BUFFER_SIZE2, array2, BUFFER_SIZE3, newNumSize);

    for (int idx = 0; idx < *newNumSize; idx++)
    {
        printf("%d\t", newNum[idx]);
    }

    return 0;
}