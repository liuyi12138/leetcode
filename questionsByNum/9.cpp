class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        stack<int> s;
        int count = 0, t = x, flag = 1;
        while(t){
            count++;
            t /= 10;
        }
        if(count % 2 == 0) flag = 0;
        while(count > 0){
            s.push(x % 10);
            x /= 10;
            count -= 2;
        }
        if(flag) s.pop();
        while(!s.empty()){
            if(x % 10 != s.top())
                return false;
            x /= 10;
            s.pop();
        }
        return true;
    }
};