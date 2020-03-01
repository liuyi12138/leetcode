class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int n = 0;
        while(!s.empty()){
            if(n == 0)
                result += (s.back() - 'A' + 1);
            else
                result += (s.back() - 'A' + 1) * pow(26,n);
            s.pop_back();
            n++;
        }
        return result;
    }
};