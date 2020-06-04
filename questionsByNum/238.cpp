class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numsSize = nums.size();
        int left = 1, right = 1;
        vector<int> output(numsSize, 1);
        for(int i = 0; i < numsSize; ++i){
            output[i] *= left;
            left *= nums[i];
            output[numsSize - i - 1] *= right;
            right *= nums[numsSize - i - 1];
        }
        return output;
    }
};