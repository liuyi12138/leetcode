#include <numeric>
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        sort(nums.begin(), nums.end());
        int tar = accumulate(nums.begin(), nums.end(), 0);
        vector<int> res;
        int sum = 0;
        int i = nums.size()-1;
        while(sum <= tar - sum){
            res.push_back(nums[i]);
            sum += nums[i];
            i--;
        }
        return res;
    }
};