class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> edges(numCourses);
        vector<int> pre(numCourses, 0);
        queue<int> q;
        for(int i = 0; i < prerequisites.size(); ++i){
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
            pre[prerequisites[i][0]]++;
        }
        for(int i = 0; i < numCourses; ++i){
            if(pre[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int t = q.front();
            res.push_back(t);
            q.pop();
            for(int v : edges[t]){
                pre[v]--;
                if(pre[v] == 0){
                    q.push(v);
                }
            }
        }
        if(res.size() != numCourses)
            return {};
        return res;
    }
};