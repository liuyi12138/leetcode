bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    bool col[9][9] = {false};
    bool row[9][9] = {false};
    bool box[10][10] = {false};
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == '.')
                continue;
            int num = board[i][j]-'0'-1;
            if(col[i][num] == true || row[j][num] == true || box[(i/3)*3+j/3][num] == true)
                return false;
            else{
                col[i][num] = true;
                row[j][num] = true;
                box[(i/3)*3+j/3][num] = true;
            }
        }
    }
    return true;
}
