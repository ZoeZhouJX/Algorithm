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
    char arr[] = " I am   from China";
    // char arr[100] = {0};
    // scanf("%[^\n]", arr);
    // fgets(arr, sizeof(arr), stdin);
    int len = strlen(arr);
    char *left = arr;
    char *right = arr + len - 1;
    reverse(left, right);
    printf("%s\n", arr);
    
    char *start = arr;
    char *current = arr;
    int count = 0;
    while (current != '\0')
    {
        for (int idx = 0; idx < len; idx++)
        {
            while (*current != '\0')
            {
                while (*start = ' ')
                {
                    start++;
                }
                while (*current != ' ' && *current != '\0')
                {
                    current++;
                }
                reverse(start, current)
            }
        }
        
        while (*current != '\0' && *current != '\0')
        {
        }

        reverse(start, arr[idx + ])
    }
    
   
    


    return 0;
}