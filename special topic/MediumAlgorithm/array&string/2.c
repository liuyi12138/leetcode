void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int colSize = matrixColSize[0];
    int* col = (int*)malloc(colSize*sizeof(int));
    for(int i = 0; i < colSize; ++i){
        col[i] = 1;
    }
    for(int i = 0; i < matrixSize; ++i){
        int flag = -1;
        for(int j = 0; j < colSize; ++j){
            if(matrix[i][j] == 0){
                if(j > flag || flag == -1){
                    col[j] = 0;
                    flag = j;
                    j = -1;
                    continue;
                }
                
            }
            else if(flag >= 0) matrix[i][j] = 0;
        }
    }
    for(int j = 0; j < colSize; ++j){
        if(col[j] == 0)
            for(int i = 0; i < matrixSize; ++i)
                matrix[i][j] = 0;
    }
}

