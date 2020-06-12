class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end(), less<int>());
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1;
            int r = nums.size()-1;
            while(l < r){
                if(nums[l] + nums[r] + nums[i] == 0){
                    res.push_back({nums[i],nums[l],nums[r]});
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[l] == nums[r-1]) r--;
                    l++;r--;
                }
                else if(nums[l] + nums[r] + nums[i] > 0)  r--;
                else l++;
            }
        }
        return res;
    }
};