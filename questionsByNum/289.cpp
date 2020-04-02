class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                int count = 0;
                for(int m = 0; m < 3; ++m){
                    for(int n = 0; n < 3; ++n){
                        if(i+m-1 < 0 || i+m-1 >= board.size() || j+n-1 < 0 || j+n-1 >= board[i].size() || (m == 1 && n == 1))
                            continue;
                        if(board[i+m-1][j+n-1] == 1 || board[i+m-1][j+n-1] == 2)
                            count++;
                    }
                }
                if(board[i][j] == 1 && (count < 2 || count > 3)){
                    board[i][j] = 2;
                }
                else if(board[i][j] == 0 && count == 3){
                    board[i][j] = 3;
                }
            }
        }
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                if(board[i][j] == 2)
                    board[i][j] = 0;
                else if(board[i][j] == 3)
                    board[i][j] = 1;
            }
        }
    }
};