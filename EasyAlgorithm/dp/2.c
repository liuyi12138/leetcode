int maxProfit(int* prices, int pricesSize){
    int start = 0;
    int max = 0;
    for(int i = 0; i < pricesSize; ++i){
        if(prices[i] - prices[start] > max) max = prices[i] - prices[start];
        if(prices[i] < prices[start]) start = i;
    }
    return max;
}
