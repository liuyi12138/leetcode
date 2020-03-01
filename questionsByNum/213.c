int getMax(int a, int b){
    int result = a > b ? a : b;
    return result;
}
    
int robI(int* nums, int l, int h){
    int dp[h-l+1];
    dp[0] = nums[l];
    dp[1] = getMax(nums[l], nums[l+1]);
    for(int i = 2; i <= h-l; ++i){
        dp[i] = getMax(dp[i-1], dp[i-2] + nums[l + i]);
    }
    return dp[h-l];
}

int rob(int* nums, int numsSize){
    if(numsSize == 0) return 0;
    if(numsSize == 1) return nums[0];
    if(numsSize == 2) return getMax(nums[0], nums[1]);
    return getMax(robI(nums, 0, numsSize-2), robI(nums, 1, numsSize-1));
}