char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0) return "";
    if(strlen(strs[0]) == 0) return "";
    char* result = (char*)malloc((strlen(strs[0])+1)*sizeof(char));
    result[0] = '\0';
    char c = strs[0][0];
    int count = 0;
    while(count < strlen(strs[0])){
        int i = 0;
        for(; i < strsSize; ++i)
            if(strs[i][count] != c) break;
        if(i < strsSize) break;
        result[count] = c;
        count++;
        c = strs[0][count];
    }
    result[count] = '\0';
    return result;
}

