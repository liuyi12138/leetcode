/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(void* a, void* b){
    return *(char*)a - *(char*)b;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    char*** result = (char***)malloc(strsSize*sizeof(char**));
    int* colSize = (int*)malloc(strsSize*sizeof(int));
    char** sortstrs = (char**)malloc(strsSize*sizeof(char*));  //排序后的单词列表 
    char** sortsize = (char**)malloc(strsSize*sizeof(char*));  //排序后的group列表
    for(int i = 0; i < strsSize; ++i){
        char* temp = (char*)malloc(26*sizeof(char));
        strcpy(temp, strs[i]);
        qsort(temp, strlen(strs[i]), sizeof(char), compare);
        sortstrs[i] = temp;
    }
    int col = 0;
    for(int i = 0; i < strsSize; ++i){
        int flag = 0;
        for(int j = 0; j < col; ++j){
            if(strcmp(sortstrs[i], sortsize[j]) == 0){
                result[j][colSize[j]] = strs[i];
                colSize[j] ++;
                flag = 1;
                break;
            }
        }
        if(!flag){
            int** tempCol = (int**)malloc((strsSize-i)*sizeof(int*));
            char* tempsort = (char*)malloc(26*sizeof(char));
            strcpy(tempsort, sortstrs[i]);
            sortsize[col] = tempsort;
            tempCol[0] = strs[i];
            colSize[col] = 1;
            result[col] = tempCol;
            col++;
        }
    }
    *returnSize = col;
    (*returnColumnSizes) = colSize;
    return result;
}

