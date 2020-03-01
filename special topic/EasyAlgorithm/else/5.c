bool isValid(char * s){
    int len = strlen(s);
    if(len == 0) return true;
    if(len < 2) return false;
    char* stack = (char*)malloc(len*sizeof(char));
    int count = 1;
    stack[0] = s[0];
    for(int i = 1; i < len; ++i){
        if(count > 0 && ((stack[count-1] == '(' && s[i] == ')') || (stack[count-1] == '[' && s[i] == ']') || (stack[count-1] == '{' && s[i] == '}')))
            count--;
        else{
            stack[count] = s[i];
            count++;
        }
    }
    free(stack);
    return count == 0;
}

