class Solution {
public:
    int dfs(int now, vector<vector<int>>& son, vector<int>& informTime){
        int max = 0;
        int temp;
        for(auto it: son[now]){
            temp = dfs(it, son, informTime);
            if(temp > max) max = temp;
        }
        return max+informTime[now];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1) return 0;
        vector<vector<int>> son(n);
        for(int i = 0; i < n; ++i){
            if(manager[i] != -1)
                son[manager[i]].push_back(i);
        }
        return dfs(headID, son, informTime);
    }
};