class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mset;
        for(auto iter : wordDict){
            mset.insert(iter);
        }
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(dp[j] && mset.find(s.substr(j, i - j)) != mset.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};