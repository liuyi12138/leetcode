class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> mmap;
        while(n != 1 && !mmap[n]){
            mmap[n] = true;
            int t = 0;
            while(n > 0){
                t += (n % 10) * (n % 10);
                n /= 10;
            }
            n = t;
        }
        return n == 1;
    }
};