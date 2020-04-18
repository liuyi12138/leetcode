class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxA = min(height[l], height[r]) * (r - l);
        while(l < r){
            if(height[l] < height[r]){
                l++;
                maxA = max(maxA, min(height[l], height[r]) * (r - l));
            }
            else{
                r--;
                maxA = max(maxA, min(height[l], height[r]) * (r - l));
            }   
        }
        return maxA;
    }
};