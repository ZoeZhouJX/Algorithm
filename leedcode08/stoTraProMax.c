#include <stdio.h>

#define PRICE_SIZE 7
int stoTraProMax(int *price, int priSize) 
{
    if (priSize < 2)
    {
        return 0;
    }

    int min = price[0];
    int curPro = 0;
    int max = 0;
    for (int idx = 0; idx < priSize; idx++)
    {
        if (price[idx] < min)
        {
            min = price[idx];
        }
        curPro = price[idx] - min;
        if (curPro > max)
        {
            max = curPro;
        }
    }

    return max;

}


int main()
{
    int max = 0;
    int price[PRICE_SIZE] = {2, 1, 3, 6, 4, 9, 7};
    max = stoTraProMax(price, PRICE_SIZE);
    printf("maxprofit:%d\n", max);

    return 0;
}