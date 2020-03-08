class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int max = light[0];
        int count = 0;
        if(max == 1) count++;
        for(int i = 1; i < light.size(); ++i){
            if(light[i] > max) max = light[i];
            if(i == max-1) count++;
        }
        return count;
    }
};