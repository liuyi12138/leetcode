int compare(void* a, void* b){
    return *(char*)a - *(char*)b;
}

int minSteps(char * s, char * t){
    int len = strlen(s);
    int sLetter[26];
    int tLetter[26];
    memset(sLetter, 0, 26*sizeof(int));
    memset(tLetter, 0, 26*sizeof(int));
    for(int i = 0; i < len; ++i){
        sLetter[s[i] - 'a'] += 1;
        tLetter[t[i] - 'a'] += 1;
    }
    int count = 0;
    for(int i = 0; i < 26; ++i){
        int temp = sLetter[i] - tLetter[i];
        if(temp > 0)
            count += temp;
        else
            count -= temp;
    }
    return count/2;
}

