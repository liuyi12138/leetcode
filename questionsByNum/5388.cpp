class Solution {
public:
    string reformat(string s) {
        if(s.size() <= 1) return s;
        string nums;
        string chars;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] <= '9' && s[i] >= '0')
                nums.push_back(s[i]);
            else
                chars.push_back(s[i]);
        }
        if(nums.size() > chars.size()+1 || chars.size() > nums.size()+1) 
            return "";
        int i = 0;
        int flag = 1;
        int size = 0;
        if(nums.size() > chars.size()){
            size = chars.size();
            flag = 0;
        }
        else{
            size = nums.size();
        }
        while(i < size){
            s[2*i+flag] = nums[i];
            s[2*i+1-flag] = chars[i];
            ++i;
        }
        if(i < chars.size()){
            s[s.size()-1] = chars[i];            
        }
        if(i < nums.size()){
            s[s.size()-1] = nums[i];            
        }
        return s;
    }
};