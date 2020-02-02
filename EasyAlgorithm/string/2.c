int reverse(int x){
    if(x > 2147483648 || x <= -2147483648) return 0;
    int flag = 0;
    if(x < 0){
        flag = 1;
        x = 0 - x;
    }
    int num[11];
    int count = 0;
    for(int i = 0; x > 0; ++i){
        num[i] = x % 10;
        x = x / 10;
        count++;
    }
    long int result = 0;
    for(int i = 0; i < count; ++i){
        result *= 10;
        result += num[i];
    }
    if(flag) result = 0 - result;
    if(result > 2147483648 || result <= -2147483648) return 0;
    return result;
}

