class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> nums;
        for(int i = 1; i <= m; ++i)
            nums.push_back(i);
        for(int i = 0; i < queries.size(); ++i){
            auto iter = find(nums.begin(), nums.end(), queries[i]);
            nums.erase(iter);
            nums.insert(nums.begin(),1,queries[i]);
            queries[i] = iter - nums.begin();
        }
        return queries;
    }
};