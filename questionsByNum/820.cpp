//暴力搜索超时
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int allLen = 0;
        for(int i = 0; i < words.size(); ++i){
            int flag = 0;
            for(int j = 0; j < words.size(); ++j){
                if(i != j && words[i].size() <= words[j].size()){
                    if(words[i].compare(0,words[j].size(),words[j],words[j].size()-words[i].size(),words[i].size()) == 0){
                        if(words[i].size() == words[j].size() && i < j)
                            allLen += (words[i].size() + 1);
                        flag = 1;
                        break;
                    }
                }
            }
            if(!flag) 
                allLen += (words[i].size() + 1);
        }
        return allLen;
    }
};

//HashSet删除后缀
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> hashSet(words.begin(), words.end());
        for(int i = 0; i < words.size(); ++i){
            for(int j = 1; j < words[i].size()-1; ++j){
                hashSet.erase(words[i].substr(j));
            }
        }
        int res = 0;
        for(auto iter: hashSet){
            res += (iter.size() + 1);
        }
        return res;
    }
};