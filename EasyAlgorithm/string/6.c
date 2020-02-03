int myAtoi(char * str){
    long int result = 0;
    int flag = 0;
    int maxflag = 0;
    int length = strlen(str);
    int i = 0;
    while(i < length && str[i] == ' ') ++i;
    if(str[i] == '+') ++i;
    else if(str[i] == '-'){
        flag = 1;
        ++i;
    }
    for(;i < length; ++i){
        if(str[i] > '9' || str[i] < '0')
            break;
        else if(result > INT_MAX){
            maxflag = 1;
            break;
        }
        else{
            int t = str[i] - '0';
            result *= 10;
            result += t;
        }
    }
    if(result > INT_MAX) maxflag = 1;
    if(maxflag){
        if(flag) return INT_MIN;
        return INT_MAX; 
    }
    else if(flag) result = 0 - result;
    return result;
}

