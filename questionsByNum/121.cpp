class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int startIndex = 0;
        for(int i = 0; i < prices.size(); ++i){
            if(prices[i] < prices[startIndex])
                startIndex = i;
            if(prices[i] - prices[startIndex] > max)
                max = prices[i] - prices[startIndex];
        }
        return max;
    }
};