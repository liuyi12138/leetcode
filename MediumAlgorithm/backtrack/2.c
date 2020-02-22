class Solution {
public:
    vector<string> result;
    void backtrack(vector<int>& rest, vector<int>& s, int depth, int count){
        if(rest[0] == 0 && rest[1] == 0){
            string s1(depth,' ');
            for(int i = 0; i < s.size(); ++i){
                if(s[i] == 1)
                    s1[i] = '(';
                else
                    s1[i] = ')';
            }
            result.push_back(s1);
            return;
        }
        if(rest[0] != 0){
            s[depth] = 1;
            rest[0] -= 1;
            backtrack(rest, s, depth+1, count+1);
            rest[0] += 1;
        }
        if(rest[1] != 0 && count != 0){
            s[depth] = 0;
            rest[1] -= 1;
            backtrack(rest, s, depth+1, count-1);
            rest[1] += 1;
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<int> rest(2,n);
        vector<int> s(2*n);
        backtrack(rest, s, 0, 0);
        return result;
    }
};