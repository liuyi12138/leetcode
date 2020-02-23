class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> result;
        int x = 1;
        int y = num+1;
        int min = y-x;
        for(int i = sqrt(num+1); i > 0; --i){
            if((num+1) % i == 0 && abs((num+1)/i - i) < min){
                x = i;
                y = (num+1)/i;
                min = abs(x-y);
            }
        }
        for(int i = sqrt(num+2); i > 0; --i){
            if((num+2) % i == 0 && abs((num+2)/i - i) < min){
                x = i;
                y = (num+2)/i;
                min = abs(x-y);
            }
        }
        result.push_back(x);
        result.push_back(y);
        return result;
    }
};