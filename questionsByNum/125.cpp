class Solution {
public:
    bool isSame(char a, char b){
        if(isdigit(a)) return a == b;
        if(a == b || a + 32 == b || a - 32 == b) return true;
        return false;
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l < r){
            while(l < r && !isalpha(s[l]) && !isdigit(s[l])) l++;
            while(l < r && !isalpha(s[r]) && !isdigit(s[r])) r--;
            if(l >= r) return true;
            if(!isSame(s[l], s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};