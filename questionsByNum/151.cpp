class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0) return "";
        string res;
        int len = s.size() - 1;
        int start = len;
        for(int i = len; i >= 0; --i){
            while(i >= 0 && s[i] == ' ') --i;
            if(i < 0) break;
            start = i;
            while(i >= 0 && s[i] != ' ') -- i;
            res += s.substr(i+1, start-i);
            res += ' ';
        }
        if(res.size() > 0)
            res.pop_back();
        return res;
    }
};