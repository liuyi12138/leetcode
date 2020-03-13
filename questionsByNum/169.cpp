class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mymap(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            mymap[nums[i]] += 1;
            if(mymap[nums[i]] > nums.size()/2)
                return nums[i];
        }
        return 0;
    }
};