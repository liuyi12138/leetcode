class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        while(s.size() > 1){
            if(s[s.size()-1] == '1'){
                int i = s.size()-1;
                while(i >= 0 && s[i] == '1'){
                    s[i] = '0';
                    --i;
                }
                if(i == -1){
                    s.insert(0,1,'1');
                }
                else{
                    s[i] = '1';
                }
            }
            else{
                s.pop_back();   
            }
            count++;
        }
        return count;
    }
};