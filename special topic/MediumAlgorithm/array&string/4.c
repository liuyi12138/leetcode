int lengthOfLongestSubstring(char * s){
    int slen = strlen(s);
    if(slen == 0) return 0;
    int maxlen = 1;
    int letter[256];
    memset(letter, -1, 256*sizeof(int));
    int nowlen[slen];
    nowlen[0] = 1;
    letter[s[0]] = 0;
    for(int i = 1; i < slen; ++i){
        int tempIndex = letter[s[i]];
        if(tempIndex >= 0){
            int distance = i - tempIndex;
            if(distance > nowlen[i-1]){
                nowlen[i] = nowlen[i-1] + 1;
            }
            else{
                nowlen[i] = distance;
            }
        }
        else{
            nowlen[i] = nowlen[i-1] + 1;
        }
        letter[s[i]] = i;
        if(nowlen[i] > maxlen)
            maxlen = nowlen[i];
        
    }
    
    return maxlen;
}

