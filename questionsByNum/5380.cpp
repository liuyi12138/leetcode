class Solution {
public:
    bool match(string a, string b){
        if(a.size() > b.size()) return false;
        if(b.find(a) != b.npos) return true;
        return false;
    }
    
    static bool comp(string& a, string&b){
        return a.size()<b.size();
    }
    
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(),comp);
        vector<string> res;
        for(int i = 0; i < words.size(); ++i){
            for(int j = i+1; j < words.size(); ++j){
                if(match(words[i],words[j])){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};