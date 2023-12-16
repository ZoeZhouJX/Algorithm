#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// #define SIZE 8

int main()
{
    int target = 0;
    scanf("%d",&target);
    int size = 0;
    printf("输入数组大小：");
    scanf("%d",&size);

    // int *array = (int*)malloc(sizeof(int)*size);
    int array[size];
    memset(array, 0, sizeof(array));
    int pos = 0;

    srand(time(NULL));
    for(int idx = 0; idx < size; idx++)
    {
        array[idx] = rand() % 10 + 1;//随机1-10
        printf("%d\t", array[idx]);
    }
    printf("\n");

    for(int idx = 0; idx < size; idx++)
    {
        if(array[idx] != target)
        {
            //原地 空间复杂度0（1）
            array[pos] = array[idx];
            printf("%d ", array[pos]);
            pos++;
        }
    }
    printf("\n");
    




    // srand(time(NULL));
    // int arr1[SIZE];
    // memset(arr, 0, SIZE);

    // for (int idx = 0; idx < SIZE; idx++)
    // {
    //     arr1[idx] = rand() % 10 + 1;
    //     printf("%d\t", arr1[idx]);
    // }
    // printf("over\n");

    // int target = rand() % 10 + 1;
    // printf("target:%d\n", target);

    

    // for(int idx = 0; idx < SIZE; idx++)
    // {
    //     if(target != arr[idx])
    //     {
            
    //     }
    // }
    return 0;
}