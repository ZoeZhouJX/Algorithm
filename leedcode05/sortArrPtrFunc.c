// 作业：将数组array3排序
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 5

void swap(char **ptr1, char **ptr2)
{
    char **temptr;
    *temptr = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = *temptr;

}

int main()
{
    char *array3[BUFFER_SIZE] = {"world", "hello", "nihao", "zhangsan", "china"};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("array3[%d] = %s\n", idx, array3[idx]);
    }
    printf("\n");

    for (int idx = 0; idx < BUFFER_SIZE - 1; idx++)
    {
        for(int jdx = 0; jdx < BUFFER_SIZE - idx -1; jdx++)
        {
            if (strcmp(array3[jdx], array3[jdx + 1]) > 0)
            {
                swap(&array3[jdx], &array3[jdx + 1]);
                // char *temp = array3[jdx];
                // array3[jdx] = array3[jdx + 1];
                // array3[jdx + 1] = temp;
            }
        }      
    }
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("array3[%d] = %s\n", idx, array3[idx]);
    }

    return 0; 
} 

