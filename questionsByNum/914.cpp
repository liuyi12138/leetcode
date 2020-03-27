class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mmap;
        for(int i = 0; i < deck.size(); ++i){
            mmap[deck[i]]++;
        }
        int t = deck.size();
        auto iter = mmap.begin();
        while(iter != mmap.end()){
            t = gcd(t, iter->second);
            ++iter;
        }
        if(t >= 2)
            return true;
        return false;
    }

    // int gcd(int x, int y){
    //     if(x % y == 0)
    //         return y;
    //     return gcd(y, x%y);
    // }
};