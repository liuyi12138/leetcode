class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), comp);
        for(int i = 0; i < intervals.size() - 1; ++i){
            if(intervals[i][1] >= intervals[i+1][0]){
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        res.push_back(intervals[intervals.size()-1]);
        return res;
    }
};