class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int maxCandies = *max_element(candies.begin(), candies.end());
        for(int iter: candies) res.push_back(iter + extraCandies >= maxCandies);
        return res;
    }
};