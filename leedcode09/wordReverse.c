#include <stdio.h>
#include <string.h>

void reverse(char *l, char *r)
{
    while (l < r)
    {
        char temp = *l;
        *l = *r;
        *r = temp;
        l++;
        r--;
    }
}






int main()
{
    char arr[] = "  I am   from China";
    // char arr[100] = {0};
    // scanf("%[^\n]", arr);
    // fgets(arr, sizeof(arr), stdin);

    int len = strlen(arr);
    int pos = 0;
    for (int idx = 0; idx < len; idx++)
    {
        if (arr[idx] != ' ')
        {
            arr[pos] = arr[idx];
            pos++;
        }
        if (arr[idx] != ' ' && arr[idx + 1] == ' ')
        {
            arr[pos] = arr[idx + 1];
            pos++;
        }
        arr[pos] = '\0';
    }
    printf("%s\n", arr);

    len = strlen(arr);
    char *left = arr;
    char *right = arr + len - 1;
    reverse(left, right);
    printf("%s\n", arr);
    
    char *start = arr;
    char *current = arr;
    while (*current != '\0')
    {
        while (*current != ' ' && *current != '\0')
        {
            current++;
        }
        reverse(start, current - 1);
        start = current + 1;
        if (*current != '\0')
        {
            current++;
        }
    }
    // arr[*current] = '\0';
    printf("%s\n", arr);

    return 0;
}