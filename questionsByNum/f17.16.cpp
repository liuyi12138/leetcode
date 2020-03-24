class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int lastMax = 0;
        int max = dp[0];
        for(int i = 1; i < nums.size(); ++i){
            dp[i] = lastMax + nums[i];
            if(dp[i-1] > lastMax)
                lastMax = dp[i-1];
            if(dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};