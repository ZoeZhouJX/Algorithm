#include <stdio.h>
#include "dynamicArrayStack.h"
#include "doubleLinkListQueue.h"

int stringIsValid(char *string, int length)
{
    int false = 0;
    int true = 1;
    if (string == NULL)
    {
        return false;
    }
    if (length % 2 != 0)
    {
        return false;
    }

    int flag = -1;

    if (flag == -1)
    {
        for (int pos = 0; pos < length; pos += 2)
        {
            if (((string[pos + 1] - string[pos] == 1) || (string[pos + 1] - string[pos] == 2)) && pos < length)
            {
                flag = -1;
                return true;
            }
            else
            {
                flag = -2;
                break;
            }
        }
        
    }
    
    if (flag == -2)
    {
        dynamicArrayStack stack;
        dynamicArrayStackInit(&stack);

        DoubleLinkListQueue *queue;
        doubleLinkListQueueInit(&queue);

        for (int idx = 0; idx < (length >> 1); idx++)
        {
            dynamicArrayStackPush(&stack, (void *)(string + idx));
        }
        for (int jdx = (length >> 1); jdx < length; jdx++)
        {
            doubleLinkListQueuePush(queue, (void *)(string + jdx));
        }

        int *val1 = NULL;
        int *val2 = NULL;
        while (!dynamicArrayStackIsEmpty(&stack) && !doubleLinkListQueueIsEmpty(queue))
        {
            dynamicArrayStackTop(&stack, (void **)&val1);
            doubleLinkListQueueTop(queue, (void **)&val2);
            if (*val1 == '(' && *val2 == ')')
            {
                dynamicArrayStackPop(&stack);
                doubleLinkListQueuePop(queue);
            }
            else if (*val1 == '[' && *val2 == ']')
            {
                dynamicArrayStackPop(&stack);
                doubleLinkListQueuePop(queue);
            }
            else if (*val1 == '{' && *val2 == '}')
            {
                dynamicArrayStackPop(&stack);
                doubleLinkListQueuePop(queue);
            }
            else
            {
                return false;
            }
        }
        dynamicArrayStackDestroy(&stack);
        doubleLinkListQueueDestroy(queue);
        return true;
    }
    
}

int main()
{
    char string[] = {'(', '{', '[', ']', '}', ')'};
    int length = sizeof(string) / sizeof(string[0]);

    int isValid = stringIsValid(string, length);
    if (isValid)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}