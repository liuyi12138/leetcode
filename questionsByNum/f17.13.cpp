class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        vector<int> dp(sentence.size()+1);
        dp[0] = 0;
        for(int i = 0; i < sentence.size(); ++i){
            dp[i+1] = dp[i] + 1;
            for(auto& word: dictionary){
                if(word.size() <= i+1 && (word == sentence.substr(i+1-word.size(), word.size()))){
                    dp[i+1] = min(dp[i+1], dp[i+1-word.size()]);
                }
            }
        }
        return dp[sentence.size()];
    }
};