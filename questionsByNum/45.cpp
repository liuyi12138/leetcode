//暴力dp，超时
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>arr(nums.size(), nums.size());
        arr[0] = 0;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 1; j <= nums[i] && i+j < nums.size(); ++j){
                arr[i+j] = min(arr[i+j], arr[i]+1);
            }
        }
        return arr[nums.size()-1];
    }
};

//贪心，实际上就是取dp中走得最远的值
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, step = 0, end = 0;
        for(int i = 0; i < nums.size()-1; ++i){
            if(maxPos >= i){
                maxPos = max(maxPos, i+nums[i]);
                if(i == end){
                    end = maxPos;
                    step++;
                }
            }
        }
        return step;
    }
};