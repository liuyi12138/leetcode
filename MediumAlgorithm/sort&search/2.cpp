//桶排序，插入部分过于复杂而超时
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> temp;
        vector<vector<int>> counter(nums.size(), temp);
        vector<int> result;
        
        for(int i = 0; i < nums.size(); ++i){
            int c = count(nums.begin(),nums.end(),nums[i]) - 1;
            if(find(counter[c].begin(), counter[c].end(), nums[i]) == counter[c].end())
                counter[c].push_back(nums[i]);
        }
        int f = counter.size()-1;
        while(k > 0 && f >= 0){
            while(counter[f].size()>0 && k > 0){
                result.push_back(counter[f][counter[f].size()-1]);
                counter[f].pop_back();
                k--;
            }
            f--;
        }
        return result;
    }
};

//使用map保存
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> temp;
        vector<vector<int>> counter(nums.size(), temp);
        vector<int> result;
        map<int,int> countmap;
        
        for(int i = 0; i < nums.size(); ++i){
            countmap[nums[i]] += 1;
        }
        
        for(auto iter = countmap.begin(); iter != countmap.end(); iter++){
            counter[iter->second-1].push_back(iter->first);
        }
        
        int f = counter.size()-1;
        while(k > 0 && f >= 0){
            while(counter[f].size()>0 && k > 0){
                result.push_back(counter[f][counter[f].size()-1]);
                counter[f].pop_back();
                k--;
            }
            f--;
        }
        return result;
    }
};