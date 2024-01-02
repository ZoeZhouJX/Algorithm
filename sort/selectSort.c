#include <stdio.h>

#define BUFFER_SIZE 7

int main()
{
    int arr[BUFFER_SIZE] = {1, 30, 24, 5, 58, 12, 39};

    int minIndex = 0;

    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        int min = arr[idx];
        for (int jdx = idx + 1; jdx < BUFFER_SIZE; jdx++)
        {
            if (arr[jdx] < min)
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
    
    for (int ndx = 0; ndx < BUFFER_SIZE; ndx++)
    {
        printf("%d\t", arr[ndx]);
    }
    printf("\n");

    return 0;
}