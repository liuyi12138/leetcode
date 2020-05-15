class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0] == k;
        int now = 0, count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int iter : nums){
            now+=iter;
            if(mp.count(now - k))
                count += mp[now - k];
            mp[now]++;
        }
        return count;
    }
};