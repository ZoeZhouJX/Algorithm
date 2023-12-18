#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define LINE 3

void *twodArrOverturn(int **arr,int size)
{
    for (int idx = 0; idx < size; idx++)
    {
        for(int jdx = idx; jdx < size; jdx++)
        {
            int temp = arr[idx][jdx];
            arr[idx][jdx] = arr[jdx][idx];
            arr[jdx][idx] = temp;
        }
    }
}


int main()
{
    int **arr = (int **)malloc(sizeof(int *) * ROW);
    for (int idx = 0; idx < ROW; idx++)
    {
       *(arr + idx) = (int *)malloc(sizeof(int) * LINE);
    }

    printf("翻转前：\n");

    int count = 1;
    for (int idx = 0; idx < ROW; idx++)
    {
        for (int jdx = 0; jdx < LINE; jdx++)
        {
            arr[idx][jdx] = count;
            printf("%d\t", count);
            count++;
        }
        printf("\n");
    }

    printf("翻转后：\n");

    twodArrOverturn(arr, ROW);

    int num = 0;
    for (int idx = 0; idx < ROW; idx++)
    {
        for (int jdx = 0; jdx < LINE; jdx++)
        {
            num++;
            printf("%d\t", arr[idx][jdx]);
        }
        printf("\n");
    }
    
    return 0;
}