int maxProfit(int* prices, int pricesSize){
    if(pricesSize == 0)
        return 0;
    int max = 0;
    int sum = 0;
    int start = prices[0];
    int end = 0;
    for(int i = 0; i < pricesSize; ++i){
        if(prices[i] < start){
            start = prices[i];
        }
        if(prices[i] - start > max){
            end = prices[i];
            max = end - start;
        }
        if(prices[i] < end){
            start = prices[i];
            sum += max;
            max = 0;
        }
    }
    sum += max;
    return sum;
}