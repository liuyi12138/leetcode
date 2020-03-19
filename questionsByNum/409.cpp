class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> strMap;
        for(int i = 0; i < s.size(); ++i){
            strMap[s[i]]++;
        }
        auto iter = strMap.begin();
        int res = 0;
        int flag = 0;
        while(iter != strMap.end()){
            if(!flag && iter->second % 2 == 1)
                flag = 1;
            res += 2*(iter->second / 2);
            iter++;
        }
        res += flag;
        return res;
    }
};