void reverseString(char* s, int sSize){
    int l = 0;
    int h = sSize - 1;
    char* c;
    while(l<h){
        c = s[l];
        s[l] = s[h];
        s[h] = c;
        ++l;
        --h;
    }
}

