//暴力dp超时
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0) return true;
        vector<bool> attach(nums.size(), false);
        attach[0] = true;
        for(int i = 0; i < nums.size(); ++i){
            if(attach[i]){
                for(int j = 1; j <= nums[i]; ++j){
                    attach[i+j] = true;
                }
            }
        }
        return attach[nums.size()-1];
    }
};

//改进版
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0) return true;
        int maxIndex = nums[0];
        for(int i = 0; i <= maxIndex && i < nums.size()-1; ++i){
            maxIndex = max(maxIndex, nums[i] + i);
        }
        return maxIndex >= nums.size()-1;
    }
};