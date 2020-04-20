class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || grid[x][y] == '0')
            return;
        grid[x][y] = '0';
        dfs(grid, x+1, y);
        dfs(grid, x-1, y);
        dfs(grid, x, y+1);
        dfs(grid, x, y-1);
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int xm = grid.size();
        int ym = grid[0].size();
        int count = 0;
        for(int i = 0; i < xm; ++i){
            for(int j = 0; j < ym; ++j){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};