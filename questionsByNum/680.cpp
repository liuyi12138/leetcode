class Solution {
public:
    bool isValid(string& s, int l, int r, int& flag){
        int t = flag;
        while(l < r){
            if(s[l] != s[r]){
                if(flag) return false;
                flag = 1;
                t = flag;
                if(isValid(s, l+1, r, flag)) return true;
                flag = t;
                if(isValid(s, l, r-1, flag)) return true;
                return false;
            }
            else{
                l++;
                r--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        if(s.size() <= 2) return true;
        int l = 0, r = s.size()-1;
        int flag = 0;
        return isValid(s, l, r, flag);
    }
};