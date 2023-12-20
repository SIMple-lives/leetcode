#include <stdio.h>

int maxProfit(int* prices, int pricesSize) //考虑事情要全面，如果没有本钱或者只有第一天的价格的时候那么他就只能进行买入而无法进行卖出.
{
    if(pricesSize == 0||pricesSize == 1) 
    {
        return 0;
    }
    int newProfit[pricesSize-1];
    for(int i = 0; i < pricesSize-1;i++)//每天可以买入也可以卖出，但当天就没有相应的利润.
    {   
        newProfit[i] = prices[i+1]-prices[i];//将前后两天的股票进行对比，如果为负数，那么证明当天价格低于前一天.如果低，则买进在后一天卖出。并且可以持续进行操作.
    }    
    int max=0;
   for(int i = 0; i < pricesSize-1;i++)//对总利润进行加和。
    {   
        if(newProfit[i]>0)
        {
            max+=newProfit[i];
        }
    }
    return max;
}

int main()
{
    int priceSize=0;
    scanf("%d",&priceSize);
    int price[priceSize];
    for(int i = 0; i < priceSize;i++)
    {
        scanf("%d",&price[i]);
    }
    int max=maxProfit(price, priceSize);
    printf("%d\n",max);
    return 0;
}