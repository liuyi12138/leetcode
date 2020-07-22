class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size() == 1) return numbers[0];
        int l = 0, r = numbers.size()-1, mid;
        while(l <= r){
            mid = (r - l)/2 + l;
            if(mid > 0 && numbers[mid] < numbers[mid-1]) return numbers[mid];
            if(numbers[mid] < numbers[r]) r = mid-1;
            else if(numbers[mid] > numbers[r])l = mid+1;
            else r--;
        }
        return numbers[0];
    }
};