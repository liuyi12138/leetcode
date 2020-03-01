char * longestPalindrome(char * s){
    int slen = strlen(s);
    if(slen == 0) return "";
    bool dp[slen][slen];
    int maxlen = 1;
    int startIdx = 0;
    for(int i = slen - 2; i >= 0; --i){
        dp[i][i] = true;
        for(int j = i + 1; j < slen; ++j){
            if(s[i] == s[j] && (j - i < 3 || dp[i+1][j-1]))
                dp[i][j] = true;
            else
                dp[i][j] = false;
            if(dp[i][j] && j - i  >= maxlen){
                maxlen = j - i + 1;
                startIdx = i;
            }
        }
    }
    char* maxstr = (char*)malloc((maxlen+1)*sizeof(char));
    // memset(maxstr, '\0', maxlen*sizeof(char));
    strncpy(maxstr, s + startIdx, maxlen);
    maxstr[maxlen] = '\0';
    return maxstr;
}

