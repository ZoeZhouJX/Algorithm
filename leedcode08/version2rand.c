#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxProfit(int prices[], int n)
{

    if (n < 2)
    {
        return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;
    int minPriceDay = 1;
    int bestBuyDay = 2;
    int betSellDay = 0;
    for (int i = 1; i < n; i++)
    {
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
            minPriceDay = i + 1;
        }
        else
        {
            int currProfit = prices[i] - minPrice;
            while (currProfit > maxProfit)
            {
                maxProfit = currProfit;
                bestBuyDay = minPriceDay;
                betSellDay = i;
            }
            // maxProfit = (currProfit > maxProfit) ? currProfit : maxProfit;
        }
    }
    printf("最佳买入天为：%d ，最佳卖出天为：%d\n", bestBuyDay, betSellDay + 1);
    return maxProfit;
}

int main()
{
    // 示例输入
    // int prices[] = {11, 31, 5, 1, 2, 4};
    // int n = sizeof(prices) / sizeof(prices[0]);
    srand(time(NULL));
    int prices[7];
    for (int idx = 0; idx < 7; idx++)
    {
        prices[idx] = rand() % 20 + 1;
        printf("%d ", prices[idx]);
    }
    printf("\n");
    // 调用函数并打印输出
    int result = maxProfit(prices, 7);
    printf("\n最大利润为: %d\n", result);

    return 0;
}