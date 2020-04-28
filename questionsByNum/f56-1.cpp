class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int allXor = 0;
        for(auto iter: nums)
            allXor ^= iter;
        int i = 1;
        while((i & allXor) == 0)
            i <<= 1;
        int a = 0,b = 0;
        for(auto iter: nums){
            if((iter & i) == 0)
                a ^= iter;
            else
                b ^= iter;
        }
        vector<int> res = {a,b};
        return res;
    }
};