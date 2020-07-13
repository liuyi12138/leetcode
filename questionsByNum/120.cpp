class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0) return 0;
        int m = triangle.size(), n = triangle[m-1].size();
        int dp[m][n];
        for(int i = 0; i < n; ++i){
            dp[m-1][i] = triangle[m-1][i];
        }
        for(int i = m-2; i >= 0; --i){
            for(int j = 0; j < triangle[i].size(); ++j){
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};