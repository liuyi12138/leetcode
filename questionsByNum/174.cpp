//dfs超时
class Solution {
public:
    void dfs(vector<vector<int>>& dungeon, int x, int y, int now, int needHp){
        if(x < 0 || x >= dungeon.size() || y < 0 || y >= dungeon[0].size()) return;
        if(x == dungeon.size()-1 && y == dungeon[0].size()-1){
            if(now + dungeon[x][y] < 0)
                needHp = max(needHp, -now-dungeon[x][y]);
            minHP = min(minHP, needHp);
            return;
        }
        dfs(dungeon, x+1, y, now + dungeon[x][y], max(needHp, -now-dungeon[x][y]));
        dfs(dungeon, x, y+1, now + dungeon[x][y], max(needHp, -now-dungeon[x][y]));
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.size() == 0) return 0;
        dfs(dungeon, 0, 0, 0, 0);
        return minHP+1;
    }
private:
    int minHP = INT_MAX;
};
//dp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[n][m - 1] = dp[n - 1][m] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int minn = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(minn - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};