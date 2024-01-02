#include <stdio.h>

int main()
{
    int len = 4;
    int len1 = len >> 1;

    int size = 9;
    int size1 = size >> 1;

    printf("%d\n%d\n", len1, size1);

    return 0;
}