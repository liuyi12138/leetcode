class Solution {
public:
    string now = "";
    vector<vector<bool>> used;
    
    bool dfs(vector<vector<char>>& board, string word, int depth, int x, int y){
        if(x < 0 || x >=used.size() || y < 0 || y >= used[0].size() || used[x][y]) return false;
        now.push_back(board[x][y]);
        used[x][y] = true;
        if(depth == word.size()-1 && word == now)
            return true;
        if(now[depth] != word[depth]){
            now.pop_back();
            used[x][y] = false;
            return false;
        }
        if(dfs(board, word, depth+1, x+1, y)) return true;
        if(dfs(board, word, depth+1, x, y+1)) return true;
        if(dfs(board, word, depth+1, x-1, y)) return true;
        if(dfs(board, word, depth+1, x, y-1)) return true;
        now.pop_back();
        used[x][y] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0)
            return (word == "");
        vector<bool> row;
        for(int j = 0; j < board[0].size(); ++j)
            row.push_back(false);
        for(int i = 0; i < board.size(); ++i)
            used.push_back(row);

        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
    
};