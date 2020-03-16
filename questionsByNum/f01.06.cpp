class Solution {
public:
    string compressString(string S) {
        if(S.size() == 0) return "";
        string res;
        int count = 1;
        char now = S[0];
        for(int i = 1; i < S.size(); ++i){
            if(S[i] == now){
                count++;
            }
            else{
                res.push_back(now);
                res += to_string(count);
                now = S[i];
                count = 1;
            }
        }
        res.push_back(now);
        res += to_string(count);
        if(res.size() >= S.size())
            res = S;
        return res;
    }
};