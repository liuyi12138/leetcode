class Solution {
public:
    int sumNums(int n) {
        int t  = n+1;
        int res = 0;
        while(n > 0){
            n&1 && (res += t);
            t<<=1;
            n>>=1;
        }
        return res>>1;
    }
};