class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int t = s3.size();
        if(m + n != t) return false;
        bool dp[m+1][n+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for(int i = 0; i <= m; ++i){
            for(int j = 0; j <= n; ++j){
                if(i > 0){
                    dp[i][j] |=  (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                }
                if(j > 0){
                    dp[i][j] |= (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
        return dp[m][n];
    }
};