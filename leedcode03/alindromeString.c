#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int count = 0;
    char *arr = "a B32c b83A";
    for (int idx = 0; idx < strlen(arr); idx++)
    {
        
        if (((64 < arr[idx]) && (arr[idx] < 91)) || ((60 < arr[idx]) && (arr[idx] < 123)))
        {
            count++;
        }
    }

    char *newArr = (char *)malloc(count * sizeof(char));
    memset(newArr, 0, count * sizeof(char));

    int pos = 0;
    for (int jdx = 0; jdx < strlen(arr); jdx++)
    {
        if ((64 < arr[jdx]) && (arr[jdx] < 91))
        {
            newArr[pos] = arr[jdx];
            pos++;
        }
        else if ((96 < arr[jdx]) && (arr[jdx] < 123))
        {
            newArr[pos] = arr[jdx] - 32;
            pos++;
        }          
    }
    printf("newArr:%s\n", newArr);

    int idx1 = 0;
    int idx2 = count - 1;
    while (idx1 != idx2)
    {
        if (newArr[idx1] == newArr[idx2])
        {
            idx1++;
            idx2--;
        }
        else
        {
            printf("fail\n");
            return 0;
        }
    }
    printf("success\n");

    return 0;
}