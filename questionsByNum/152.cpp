class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 1;
        if(nums.size() == 1) return nums[0];
        int res = nums[0];
        vector<int> dpmax(nums.size(), 0);
        vector<int> dpmin(nums.size(), 0);
        dpmax[0] = nums[0];
        dpmin[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            dpmax[i]  = max(nums[i], max(dpmax[i-1] * nums[i], dpmin[i-1] * nums[i]));
            dpmin[i] = min(nums[i], min(dpmax[i-1] * nums[i], dpmin[i-1] * nums[i]));
            res = max(res, dpmax[i]);
        }
        return res;
    }
};