class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = 1;
        vector<int> res(num_people,0);
        while(candies > 0){
            if(candies >= n){
                res[(n-1) % num_people] += n;
                candies -= n;
                n++;
            }
            else{
                res[(n-1) % num_people] += candies;
                return res;
            }
        }
        return res;
    }
};