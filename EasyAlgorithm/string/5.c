bool Judge(char c){
    c = tolower(c);
    if((c > 'z' || c < 'a') && (c > '9' || c < '0')) return false;
    return true;
}

bool isPalindrome(char * s){
    int sSize = strlen(s);
    int l = 0;
    int h = sSize - 1;
    while(l < h){
        if(!Judge(s[l])) l++;
        else if(!Judge(s[h])) h--;
        else{
            if(tolower(s[l]) != tolower(s[h])) return false;
            else{
                l++;
                h--;
            } 
        }

    }
    return true;
}

