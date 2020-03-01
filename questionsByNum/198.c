int getMax(int a, int b){
    int result = a > b ? a : b;
    return result;
}
    
int rob(int* nums, int numsSize){
    if(numsSize == 0) return 0;
    if(numsSize == 1) return nums[0];
    int dp[numsSize];
    dp[0] = nums[0];
    dp[1] = getMax(nums[0], nums[1]);
    for(int i = 2; i < numsSize; ++i){
        dp[i] = getMax(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[numsSize-1];
}