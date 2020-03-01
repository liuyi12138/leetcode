int strStr(char * haystack, char * needle){
    if(strlen(needle) == 0) return 0;
    int haylen = strlen(haystack);
    int nelen = strlen(needle);
    if(haylen < nelen) return -1;
    int i = 0;
    int j = 0;
    while(i < haylen && j < nelen){
        if(haystack[i] == needle[j]){
            ++i;
            ++j;
        }
        else{
            i -= (j-1);
            j = 0;
        }
    }
    if(j == 0 || j < nelen) return -1;
    return i - nelen;
}

