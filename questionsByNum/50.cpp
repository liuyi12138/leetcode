class Solution {
public:
    double doublePow(double x, long int n){
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n % 2 == 0) return doublePow(x*x, n/2);
        else return x*doublePow(x*x, n/2);
    }

    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        if(n == 0) return 1;
        long int N = n;
        if(n < 0){
             N = 0 - N;
             return 1/doublePow(x, N);
        }
        return doublePow(x, N);
    }
};