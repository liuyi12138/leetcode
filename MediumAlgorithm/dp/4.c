int lengthOfLIS(int* nums, int numsSize){
    if(numsSize < 2) return numsSize;
    int dp[numsSize];
    int maxlen = 1;
    for(int i = 0; i < numsSize; ++i){
        dp[i] = 0;
        for(int j = i-1; j >= 0; --j){
            if(nums[j] < nums[i] && dp[j] > dp[i]){
                dp[i] = dp[j];
            }
        }
        dp[i] = dp[i] + 1;
        if(dp[i] > maxlen)
            maxlen = dp[i];
    }
    return maxlen;
}