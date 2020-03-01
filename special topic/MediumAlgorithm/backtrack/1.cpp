class Solution {
public:
    vector<string> result;
    unordered_map<char, string> table{
            {'0', " "}, {'1',"*"}, {'2', "abc"},
            {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
            {'9',"wxyz"}};
    
    void backtrack(string str, string &digits, int depth){
        if(str.size() == digits.size()){
            result.push_back(str);
            return;
        }
        string tmp = table[digits[depth]];
        for (char c:tmp) {
            str += c;
            backtrack(str, digits, depth+1);
            str.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return result;
        backtrack("",digits,0);
        return result;
    }
};