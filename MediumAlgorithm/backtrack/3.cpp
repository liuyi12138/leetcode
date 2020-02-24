class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<bool>& used, vector<int>& now, vector<int>& nums, int depth){
        if(depth == nums.size()){
            result.push_back(now);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(!used[i]){
                used[i] = true;
                now[depth] = nums[i];
                backtrack(used, now, nums, depth+1);
                used[i] = false;
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        vector<int> now(nums.size());
        backtrack(used, now, nums, 0);
        return result;
    }
};