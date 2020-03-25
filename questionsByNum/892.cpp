class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int count = 0;
        int cover = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                count += grid[i][j];
                cover += grid[i][j] > 1 ? grid[i][j] - 1 : 0;
                if(i > 0){
                    cover += min(grid[i][j], grid[i-1][j]);
                }
                if(j > 0){
                    cover += min(grid[i][j], grid[i][j-1]);
                }
            }
        }
        return count*6 - cover*2; 
    }
};