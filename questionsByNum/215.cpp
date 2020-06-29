class Solution {
public:
    int fastSelect(vector<int>& nums, int start, int end, int k){
        int keyIndex = start, l = start, h = end;
        while(l < h){
            while(l < h && nums[keyIndex] >= nums[h])
                h--;
            while(l < h && nums[keyIndex] <= nums[l])
                l++;
            swap(nums[l], nums[h]);
        }
        swap(nums[l], nums[keyIndex]);
        if(l == k-1) return nums[l];
        if(l > k-1) return fastSelect(nums, start, l-1, k);
        return fastSelect(nums, l+1, end, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return fastSelect(nums, 0, nums.size()-1, k);
    }
};