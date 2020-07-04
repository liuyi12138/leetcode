class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() < 2) return 0;
        stack<int> mstack;
        int  maxlen = 0;
        mstack.push(-1);
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ')'){
                mstack.pop();
                if(mstack.empty()) mstack.push(i);
                else maxlen = max(maxlen, i - mstack.top());
            }
            else{
                mstack.push(i);
            }
        }
        return maxlen;
    }
};