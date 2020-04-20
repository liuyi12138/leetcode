class Solution {
public:
    const long long mod = 1e9 + 7; 
    int numOfArrays(int n, int m, int k) {
        long long dp[n + 1][105][k + 2];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= m; j++){
                for(int l = 0; l <= k; l++){
                    for(int r = 1; r <= m; r++){
                        if(r > j){
                            dp[i + 1][r][l + 1] += dp[i][j][l];
                            dp[i + 1][r][l + 1] %= mod;
                        }
                        else {
                            dp[i + 1][j][l] += dp[i][j][l];
                            dp[i + 1][j][l] %= mod;
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for(int i = 1; i <= m; i++){
            ans += dp[n][i][k];
            ans %= mod;
        }
        return ans;
    }
};
