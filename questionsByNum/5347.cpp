class Solution {
public:
    int minCost(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        if(n==m&&n==1)return 0;
        int dp[101][101];
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)dp[i][j]=1e5+5;
        queue<pair<int,int>>q;
        q.push({0,0});
        dp[0][0]=0;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            if(x==n-1&&y==m-1)continue;
            for(int i=0;i<4;i++){
                int tx=x+dir[i][0];
                int ty=y+dir[i][1];
                if(tx>=0&&ty>=0&&tx<n&&ty<m){
                    if(g[x][y]-1==i){   
                        if(dp[tx][ty]>dp[x][y]){
                            dp[tx][ty]=dp[x][y];
                            q.push({tx,ty});
                        }
                    }
                    else{
                        if(dp[tx][ty]>dp[x][y]+1){
                            dp[tx][ty]=dp[x][y]+1;
                            q.push({tx,ty});
                        }
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
    private:
    int dir[4][2]={0,1,0,-1,1,0,-1,0};
};