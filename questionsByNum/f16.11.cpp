class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if(k == 0) return res;
        long now = shorter*k;
        res.push_back(now);
        if(shorter == longer) return res;
        for(int i = 0; i < k; ++i){
            now += (longer - shorter);
            res.push_back(now);
        }
        return res;
    }
};