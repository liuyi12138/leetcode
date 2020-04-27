class Solution {
public:
    int searchPoint(vector<int>&nums){
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[i-1])
                return i;
        }
        return 1;
    }

    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return nums[0] == target ? 0 : -1;
        int point = searchPoint(nums);
        int l,h,mid;
        if(target >= nums[0] && target <= nums[point-1]){
            l = 0;
            h = point-1;
        }
        else if(target >= nums[point] && target <= nums[nums.size()-1]){
            l = point;
            h = nums.size()-1;
        }
        else{
            return -1;
        }
        while(l <= h){
            mid = l + (h-l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};