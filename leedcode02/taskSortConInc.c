#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define size 10
#define back2 8
#define back1 9
int main()
{
    srand(time(NULL));
    int arr[size];
    memset(arr, 0, sizeof(arr));
   
    for(int idx = 0; idx < size; idx++)
    {
        arr[idx] = rand() % 10 + 1;
    }

    for(int idx = 0; idx < size ; idx++)
    {
        for(int jdx = 0; jdx < size - 1; jdx++)
            {
                if(arr[jdx] > arr[jdx + 1])
                {
                int temp = arr[jdx];
                arr[jdx] = arr[jdx + 1];
                arr[jdx + 1] = temp;
                }
            }
    }
    for(int jdx = 0;jdx < size; jdx++)
    {
        printf("%d\t", arr[jdx]);
    }
    printf("over\n");

    for(int ndx = 0; ndx < size - 1; ndx++)
    {
        if((arr[ndx]) != (arr[ndx + 1]))
        {
            printf("%d\n", arr[ndx]);
        }
    }
    printf("%d\n", arr[back1]);
    
    return 0;
}