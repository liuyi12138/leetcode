class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int res = 0;
        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j){
                if(board[i][j] == 'R'){
                    for(int m = i; m >= 0; --m){
                        if(board[m][j] == 'B')
                            break;
                        if(board[m][j] == 'p'){
                            res += 1;
                            break;
                        }
                    }
                    for(int m = i; m < 8; ++m){
                        if(board[m][j] == 'B')
                            break;
                        if(board[m][j] == 'p'){
                            res += 1;
                            break;
                        }
                    }
                    for(int n = i; n >= 0; --n){
                        if(board[i][n] == 'B')
                            break;
                        if(board[i][n] == 'p'){
                            res += 1;
                            break;
                        }
                    }
                    for(int n = i; n < 8; ++n){
                        if(board[i][n] == 'B')
                            break;
                        if(board[i][n] == 'p'){
                            res += 1;
                            break;
                        }
                    }
                    return res;
                }
            }
        }
        return res;
    }
};