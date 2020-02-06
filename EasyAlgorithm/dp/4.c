int rob(int* nums, int numsSize){
    int dp[numsSize + 2];
    dp[numsSize + 1] = 0;
    dp[numsSize] = 0;
    for(int i = numsSize-1; i >= 0; --i){
        dp[i] = (dp[i+1] > (dp[i+2] + nums[i]) ? dp[i+1] : dp[i+2] + nums[i]);
    }
    return dp[0];
}

