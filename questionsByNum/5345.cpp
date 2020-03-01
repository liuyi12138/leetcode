//计算加权，算法本身没问题，但会造成溢出
class Solution {
public:
 
    static bool cmp(pair<char,int> a, pair<char,int> b) {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
    string rankTeams(vector<string>& votes) {
        if(votes.size() == 1) return votes[0];
        unordered_map<char,int> m;
        for(int i = 0; i < votes[0].size(); ++i){
            m.insert(make_pair(votes[0][i], 0));
        }
        for(int i = 0; i < votes.size(); ++i){
            for(int j = 0; j < votes[i].size(); ++j){
                m[votes[i][j]] += pow(2, (votes[i].size() - j - 1));
            }
        }
        
        vector<pair<char,int>> vec;
        for(auto it = m.begin(); it != m.end(); it++){
            vec.push_back(pair<char,int>(it->first,it->second));
        }   
        sort(vec.begin(),vec.end(),cmp);
        
        string result;
        for(int i = 0; i < vec.size(); ++i){
            result.push_back(vec[i].first);
        }
        return result;
    }
};

//map计数，这种sort方式确实很精髓
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if(votes.size() == 1) return votes[0];
        unordered_map<char,unordered_map<int,int>> m;
        for(int i = 0; i < votes.size(); ++i){
            for(int j = 0; j < votes[i].size(); ++j){
                m[votes[i][j]][j]++;
            }
        }
        
        string result = votes[0];
        sort(result.begin(),result.end(),[&](char a, char b){
            for(int i = 0; i < m.size(); ++i){
                if(m[a][i] > m[b][i]) return true;
                if(m[a][i] < m[b][i]) return false;
            }
            return a < b;     
        });

        return result;
    }
};