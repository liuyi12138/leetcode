class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        int low = 0;
        int high = nums.size()-1;
        int mid;
        int flag = 0;
        while(low <= high){
            mid = low + (high - low)/2;
            if(nums[mid] == target){
                flag = 1;
                break;
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        if(flag){
            int left = mid;
            while(left > 0 && nums[left-1] == target)
                left--;
            int right = mid;
            while(right < nums.size()-1 && nums[right+1] == target)
                right++;
            result[0] = left;
            result[1] = right; 
        }
        return result;
    }
};