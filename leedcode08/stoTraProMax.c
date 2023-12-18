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
    int minPriDay = 0;
    int buyDay = 0;
    int sellDay = 0;
    for (int idx = 0; idx < priSize; idx++)
    {
        if (price[idx] <= min)
        {
            min = price[idx];
            minPriDay = idx + 1;
        }
        curPro = price[idx] - min;
        if (curPro >= max)
        {
            max = curPro;
            buyDay = minPriDay;
            sellDay = idx + 1;
        }
    }
    printf("buyDay:%d\nsellDay:%d\n", buyDay, sellDay);
    return max;

}


int main()
{
    int max = 0;
    int price[PRICE_SIZE] = {3, 7, 6, 9, 4, 2, 1};
    max = stoTraProMax(price, PRICE_SIZE);
    printf("maxprofit:%d\n", max);

    return 0;
}