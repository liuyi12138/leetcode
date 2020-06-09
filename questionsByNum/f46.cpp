class Solution {
public:
    int translateNum(int num) {
        if(num < 10) return 1;
        return translateNum(num/10) + ((num%100 > 25 || num%100 < 10) ? 0 : translateNum(num / 100));
    }
};