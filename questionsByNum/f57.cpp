class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int count = 1;
        while(target > 0){
            target -= count;
            count ++;
            if(target > 0 && target % count == 0){
                vector<int> temp;
                for(int i = 0; i < count; ++i){
                    temp.push_back(target/count + i);
                }
                res.push_back(temp);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};