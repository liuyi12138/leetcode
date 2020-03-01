int coinChange(int* coins, int coinsSize, int amount){
    int count[amount+1];
    memset(count, -1, (amount+1)*sizeof(int));
    count[0] = 0;
    for(int i = 0; i < coinsSize; ++i){
        if(coins[i] <= amount){
            count[coins[i]] = 1;
        }

    }
    for(int i = 1; i <= amount; ++i){
        for(int j = 0; j < coinsSize; ++j){
            if(coins[j] < i && count[i-coins[j]] != -1){
                if(count[i] == -1)
                    count[i] = count[i-coins[j]] + 1;
                else if(count[i] > count[i-coins[j]] + 1)
                    count[i] = count[i-coins[j]] + 1;
            }
        }
        // printf("%d %d\n",i,count[i]);
    }
    return count[amount];
}

