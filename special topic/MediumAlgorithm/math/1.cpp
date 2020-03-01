class Solution {
public:
    bool isHappy(int n) {
        while(true){
            int sum = 0;
            while(n > 0){
                sum += (n%10) * (n%10);
                n = n/10;
            }
            if(sum == 1)
                return true;
            if(sum == 4)
                return false;
            n = sum;
        }
    }
};