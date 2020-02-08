

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    int* colSize = (int*)malloc(numRows*sizeof(int));
    int** result = (int**)malloc(numRows*sizeof(int*));
    *returnColumnSizes = colSize;
    if(numRows == 0) return NULL;
    int* first = (int*)malloc(sizeof(int));
    colSize[0] = 1;
    first[0] = 1;
    result[0] = first;
    for(int i = 1; i < numRows; ++i){
        colSize[i] = i+1;
        int* temp = (int*)malloc((i+1)*sizeof(int));
        temp[0] = 1;
        temp[i] = 1;
        for(int j = 1; j < i; ++j){
            temp[j] = result[i-1][j] + result[i-1][j-1];
        }
        result[i] = temp;
    }
    return result;
}

