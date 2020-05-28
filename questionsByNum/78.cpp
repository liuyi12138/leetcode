//回溯
class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& now, int depth){
        res.push_back(now);
        for(int i = depth; i < nums.size(); ++i){
            now.push_back(nums[i]);
            dfs(nums, res, now, i+1);
            now.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> now;
        dfs(nums, res, now, 0);
        return res;
    }
};

//DFS
class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& now, int depth){
        if(depth == nums.size()){
            res.push_back(now);
            return;
        }
        now.push_back(nums[depth]);
        dfs(nums, res, now, depth+1);
        now.pop_back();
        dfs(nums, res, now, depth+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> now;
        dfs(nums, res, now, 0);
        return res;
    }
};

