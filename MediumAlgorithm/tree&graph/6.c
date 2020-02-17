void dfs(int x, int y, int maxX, int maxY, char** grid) {
    if (0 <= x && x < maxX && 0 <= y && y < maxY && grid[x][y] == '1'){
        grid[x][y] = '0';
        dfs(x - 1, y, maxX, maxY, grid);
        dfs(x + 1, y, maxX, maxY, grid);
        dfs(x, y - 1, maxX, maxY, grid);
        dfs(x, y + 1, maxX, maxY, grid);        
    }

}


int numIslands(char** grid, int gridSize, int* gridColSize){
    if(gridSize == 0) return 0;
    int count = 0;
    for(int i = 0; i < gridSize; ++i) {
        for(int j = 0; j < gridColSize[0]; ++j) {
            if(grid[i][j] == '1') {
                count++;
                dfs(i, j, gridSize, gridColSize[0], grid);
            }
        }
    }
    return count;
}

