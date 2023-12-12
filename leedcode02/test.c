#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define size 10
void main()
{
    srand(time(NULL));
    int arr[size];
    memset(arr, 0, size);

    for(int idx = 0; idx < size; idx++)
    {
        arr[idx] = rand() % 10 + 1;
    }
    printf("生成的数组：\n");
    for(int idx = 0; idx < size; idx++)
    {
        printf("%d ",arr[idx]);
    }
    int target = rand() % 20 + 1;
    int idx1;
    int idx2;
    for(idx1 = 0; idx1 < size - 1; idx1++)
    {
        for(idx2 = idx1 + 1; idx2 < size; idx2++)
        {
            if(arr[idx1] + arr[idx2] == target)
            {
                printf("第%d个数和第%d个数的和等于%d\n", idx1 + 1, idx2 + 1, target);
                return;
            }
            
        }
    }
printf("\n不存在\n");
return;

}

