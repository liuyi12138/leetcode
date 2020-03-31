class Solution {
public:
    void fastSort(vector<int>& nums, int start, int end){
        int l = start;
        int h = end;
        if(l >= h)
            return;
        while(l < h){
            while(nums[h] >= nums[start] && l < h)
                h--;
            while(nums[l] <= nums[start] && l < h)
                l++;
            if(l < h){
                swap(nums[l], nums[h]);
            }
        }
        swap(nums[start], nums[l]);
        fastSort(nums, start, l-1);
        fastSort(nums, l+1, end);
        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        fastSort(nums, 0, nums.size()-1);
        return nums;
    }
};