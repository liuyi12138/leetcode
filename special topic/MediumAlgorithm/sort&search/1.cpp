class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> temp(3,0);
        for(int i = 0; i < nums.size(); ++i)
            temp[nums[i]]++;
        int n = 0;
        for(int i = 0; i < 3; ++i){
            while(temp[i] > 0){
                nums[n] = i;
                ++n;
                temp[i]--;
            }
        }
        
    }
};