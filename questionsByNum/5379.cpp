class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int dp[50003] = {0};
        int sum = 0;
        for(int n = stoneValue.size(), i = n-1; i >= 0; i--) {
            dp[i] = -0x7FFFFFFE;
            sum += stoneValue[i];
            for(int j = 1; j <= 3; j++) {
                dp[i] = max(dp[i], sum - dp[i+j]);
            }
        }
        if(sum - dp[0] == dp[0]) {
            return "Tie";
        } else if(sum - dp[0] > dp[0]) {
            return "Bob";
        }
        return "Alice";
    }
};