int climbStairs(int n){
    if(n <= 1) return 1;
    int last = 1;
    int llast = 1;
    int result;
    int i = 2;
    while(i <= n){
        result = last + llast;
        llast = last;
        last = result;
        ++i;
    }
    return result;
}

