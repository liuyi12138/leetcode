class Solution {
public:
    vector<string> res;

    void dfs(int left, int right, int n, string& temp) {
        if(right > left) return;
        if(right == left && left == n){
            res.push_back(temp);
            return;
        }
        if(left < n){
            temp.push_back('(');
            dfs(left+1, right, n, temp);
            temp.pop_back();
        }
        if(right < n && right < left){
            temp.push_back(')');
            dfs(left, right+1, n, temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        dfs(0, 0, n, temp);
        return res;
    }
};