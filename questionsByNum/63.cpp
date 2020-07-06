//dp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        dp[0][0] = 1;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(obstacleGrid[i][j] == 0) {
                    if(i > 0) dp[i][j] += dp[i-1][j];
                    if(j > 0) dp[i][j] += dp[i][j-1];
                }

            }
        }
        return dp[m-1][n-1];
    }
};

//dfs超时
class Solution {
public:
    void dfs(vector<vector<int>>& obstacleGrid, int x, int y, int m, int n){
        if(x == m-1 && y == n-1){res++; return;}
        if(x >= m || y >= n || obstacleGrid[x][y] || visited[x][y]) return;
        visited[x][y] = true;
        dfs(obstacleGrid, x+1, y, m, n);
        dfs(obstacleGrid, x, y+1, m, n);
        visited[x][y] = false;
        return;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        memset(visited, false, sizeof(visited));
        dfs(obstacleGrid, 0, 0, m, n);
        return res;
    }
private:
    bool visited[101][101];
    int res = 0;
};