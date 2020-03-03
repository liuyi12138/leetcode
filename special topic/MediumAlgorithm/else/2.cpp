class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); ++i){
            if(s.empty())
                s.push(atoi(tokens[i].c_str()));
            else if(tokens[i].size() == 1 && (tokens[i][0] < '0' || tokens[i][0] > '9')){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(tokens[i] == "+")
                    s.push(b+a);
                else if(tokens[i] == "-")
                    s.push(b-a);
                else if(tokens[i] == "*")
                    s.push(b*a);
                else if(tokens[i] == "/")
                    s.push(b/a);
            }
            else
                s.push(atoi(tokens[i].c_str()));
        }
        return s.top();
    }
};