class Solution {
public:
    int count = 0;

    bool Judge(int x, int y,int k){
        return (x/10 + x%10 + y/10 + y%10) <= k;
    }

    void dfs(int x, int y, int m, int n, int k, vector<bool>& used){
        if(x < 0 || x >= m || y < 0 || y >= n || used[x*n + y]) return;
        used[x*n + y] = true;
        if(Judge(x,y,k)){
            count++;
            dfs(x-1,y,m,n,k,used);
            dfs(x+1,y,m,n,k,used);
            dfs(x,y-1,m,n,k,used);
            dfs(x,y+1,m,n,k,used);
        } 
    }

    int movingCount(int m, int n, int k) {
        vector<bool> used(m*n,false);
        dfs(0,0,m,n,k,used);
        return count;
    }
};