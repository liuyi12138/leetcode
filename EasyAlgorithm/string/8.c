void getNext(char* s, char* next){
    int slen = strlen(s);
    int count = 0;
    int n = 0;
    char c = s[0];
    for(int i = 0; i < slen; ++i){
        if(s[i] == c){
            count++;
        }
        else{
            next[n] = count + '0';
            next[n+1] = c;
            c = s[i];
            count = 1;
            n += 2;
        }
    }
    next[n] = count + '0';
    next[n+1] = c;
    n += 2;
    next[n] = '\0';
    strcpy(s, next);
    return ;
}

char * countAndSay(int n){
    char* s = (char*)malloc(5000);
    char* next = (char*)malloc(5000);
    s[0] = '1';
    s[1] = '\0';
    for(int i = 1; i < n; ++i){
        getNext(s, next);
    }
    return s;
}

