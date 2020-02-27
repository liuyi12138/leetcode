class Solution {
public:
    int findMid(vector<int>& nums){
        int l = 0;
        int h = nums.size() - 1;
        int mid;
        while(l <= h){
            mid = (l + h) / 2;
            if(nums[mid] > nums[nums.size() - 1]){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return l;
    }

    int findResult(vector<int>& nums, int  l, int h, int target){
        int mid;
        while(l <= h){
            mid = (l + h) / 2;
            if(target == nums[mid]) return mid;
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int mid = findMid(nums);
        int l,h;
        if(target <= nums[nums.size()-1]){
            l = mid;
            h = nums.size()-1;
        }
        else{
            l = 0;
            h = mid - 1;
        }
        return findResult(nums, l, h, target);
    }
};