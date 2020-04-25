class Solution {
public:
    vector<vector<int>> res;
    vector<int> now;
    void dfs(vector<int>& nums, vector<bool>& used, int deepth){
        if(deepth == used.size())
            res.push_back(now);
        for(int i = 0; i < nums.size(); ++i){
            if(!used[i]){
                now.push_back(nums[i]);
                used[i] = true;
                dfs(nums, used, deepth+1);
                used[i] = false;
                now.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        dfs(nums, used, 0);
        return res;
    }
};