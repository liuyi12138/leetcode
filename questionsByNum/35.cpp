class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid;
        while(l <= r){
            mid = (r - l)/2 + l;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid -1;
            else l = mid + 1;
        }
        if(nums[mid] < target) return mid+1;
        else return mid;
    }
};