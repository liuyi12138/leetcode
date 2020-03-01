class Solution {
public:
    vector<vector<int>> result;
    vector<int> now;
    void dfs(vector<int>& nums, int depth){
        if(depth == nums.size()){
            result.push_back(now);
            return;
        }
        now.push_back(nums[depth]);
        dfs(nums, depth+1);
        now.pop_back();
        dfs(nums, depth+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return result;
    }
};



