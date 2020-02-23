class Solution {
public:
    int nums[10];
    int del(int m){
        for(int i = 1; i < 10; ++i){
            if(nums[i] && i % 3 == m){
                nums[i]--;
                return 1;
            }
        }
        return 0;
    }

    string largestMultipleOfThree(vector<int>& digits) {
        int sum = 0;
        for(int i = 0; i < digits.size(); ++i){
            nums[digits[i]] ++;
            sum += digits[i];
        }
        if(sum == 0)
            return "0";
        int flag = 1;
        if(sum % 3 == 2){
            if(!del(2)){
                flag = del(1) & del(1);
            }
        }
        else if(sum % 3 == 1){
            if(!del(1)){
                flag = del(2) & del(2);
            }
        }
        string result = "";
        if(flag){
            for(int i = 9; i >= 0; --i){
                while(nums[i]){
                    result += (i + '0');
                    nums[i]--;
                }
            }
        }

        return result;
    }
};