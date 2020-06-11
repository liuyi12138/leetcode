class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        res[T.size()-1] = 0;
        for(int i = T.size()-2; i >= 0; --i){
            int now = i + 1;
            while(res[now] != 0 && T[now] <= T[i]){
                now += res[now];
            }
            if(T[now] <= T[i]) res[i] = 0;
            else res[i] = now - i;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<int> s;
        for(int i = 0; i < T.size(); ++i){
            while(!s.empty() && T[i] > T[s.top()]){
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};