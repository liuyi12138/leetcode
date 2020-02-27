class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size() == 0) return result;
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2){return v1[0] < v2[0];});
        for(int i = 0; i < intervals.size()-1; ++i){
            if(intervals[i][1] >= intervals[i+1][0]){
                intervals[i+1][0] = intervals[i][0];
                if(intervals[i][1] >= intervals[i+1][1])
                    intervals[i+1][1] = intervals[i][1];
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        result.push_back(intervals[intervals.size()-1]);
        return result;
    }
};