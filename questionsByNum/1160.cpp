class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        vector<int> myChars(26,0);
        for(int i = 0; i < chars.size(); ++i){
            myChars[chars[i] - 'a']++;
        }
        for(int i = 0; i < words.size(); ++i){
            vector<int> tempChars(myChars);
            int flag = 0;
            for(int j = 0; j < words[i].size(); ++j){
                if(tempChars[words[i][j] - 'a'] > 0)
                    tempChars[words[i][j] - 'a']--;
                else{
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                res += words[i].size();
            }
        }
        return res;
    }
};