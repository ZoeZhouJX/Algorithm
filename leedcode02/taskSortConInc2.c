#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 10

int main()
{
    srand(time(NULL));
    int arr[SIZE];
    memset(arr, 0, SIZE);

    for(int idx = 0; idx < SIZE; idx++)
    {
        arr[idx] = rand() % 20 + 1;
        printf("%d\t", arr[idx]);
    }
    printf("over\n");

    int minIndex = 0;

    for (int idx = 0; idx < SIZE; idx++)
    {
        int min = arr[idx];
        for(int jdx = idx + 1; jdx < SIZE; jdx++)
        {
            if(arr[jdx] < min)
            {
                min = arr[jdx];
                minIndex = jdx;
            }
           
        }

        if (arr[idx] > min)
        {
            int temp = arr[idx];
            arr[idx] = min;
            arr[minIndex] = temp;
        }
    }

    for(int idx = 0; idx < SIZE; idx++)
    {
        printf("%d\n", arr[idx]);
    }

    return 0;
}