#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFFER_SIZE 5
#define MERGE_SIZE 10

#if 0
int main()
{
    int arr1[BUFFER_SIZE] = {1, 1, 2, 3, 4};
    int arr2[BUFFER_SIZE] = {1, 2, 3, 4, 5};
    int merge[MERGE_SIZE];
    int jdx = 0;

    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        if(arr1[idx] < arr2[idx])
        {
            merge[jdx] = arr1[idx];
            merge[jdx + 1] = arr2[idx];
        }
        else
        {
            merge[jdx] = arr2[idx];
            merge[jdx + 1] = arr1[idx];
        }
        jdx += 2;
    }
    for (int idx = 0; idx < MERGE_SIZE; idx++)
    {
        printf("%d\t", merge[idx]);
    }
    printf("\n");

    return 0;
}
#endif

    //数组作为函数的返回值
    int *mergeOrderNums(int *num1, int num1Size, int *num2, int num2Size, int* newSize)
    {
        int arrayLen = num1Size + num2Size;
        int *newArray = (int *)malloc(sizeof(int) * arrayLen);

        //必须是== 不能是= 因为=是赋值操作
        if(newArray == NULL)
        {
            return NULL;
        }

        int idx1 = 0;
        int idx2 = 0;
        int pos = 0;
        while(idx1 < num1Size && idx2 < num2Size)
        {
            if(num1[idx1] <= num2[idx2])
            {
                newArray[pos] = num1[idx1];
                idx1++;
            }
            else
            {
                newArray[pos] = num2[idx2];
                idx2++;
            }
            pos++;
        
        }
        if (idx1 == num1Size)
        {
            for (int idx = idx2; idx < num2Size; idx++)
            {
                newArray[pos++] = num2[idx];
            }
        }
        else if(idx2 == num2Size)
        {
            for (int idx = idx1; idx < num1Size; idx++)
            {
                newArray[pos++] = num1[idx];
            }
        }
        *newSize = arrayLen;
        return newArray;
    }

    int main()
    {
        int num1[] = {1, 1, 2, 15, 67};
        int num2[] = {1, 2, 2, 7, 19, 156, 231};

        int num1Len = sizeof(num1) / sizeof(num1[0]);
        int num2Len = sizeof(num2) / sizeof(num2[0]);

        int newSize = 0;
        int *newArray = mergeOrderNums(num1, num1Len, num2, num2Len, &newSize);

        for(int idx = 0; idx < newSize; idx++)
        {
            printf("newArray[%d] = %d\n", idx, newArray[idx]);
        }

        return 0;
    }