//暴力搜索
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            int count = 0;
            for(int j = 0; j < nums.size(); ++j){
                if(nums[j] < nums[i])
                    count++;
            }
            res.push_back(count);
        }
        return res;
    }
};

//sort+原数组查找
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;
        vector<int> temp(nums);
        sort(nums.begin(), nums.end(), [](int a, int b){return a < b;});
        for(int i = 0; i < temp.size(); ++i){
            result.push_back(find(nums.begin(), nums.end(), temp[i]) - nums.begin());
        }
        return result;
    }
};