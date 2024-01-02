#include <stdio.h>

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