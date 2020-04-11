//暴力dp超时
class Solution {
public:
    int dp[100][10000];
    int superEggDrop(int k, int N) {
        if(k == 1 || N <= 1 ) return N;
        int min = N;
        for(int i = N; i > 0; --i){
            int t,t1,t2;
            if(dp[k][i-1]) t1 = dp[k][i-1];
            else{
                t1 = superEggDrop(k,i-1);
                dp[k][i-1] = t1;
            }

            if(dp[k-1][N-i]) t2 = dp[k-1][N-i];
            else{
                t2 = superEggDrop(k-1,N-i);
                dp[k-1][N-i] = t2;
            }
            
            t = max(t1,t2)+1;
            if(t < min) min = t;
        }
        return min;
    }
};

//dp+二分法
class Solution {
public:
    int dp[101][10001];
    int superEggDrop(int k, int N) {
        if(k == 1 || N <= 1) return N;
        if(dp[k][N]) return dp[k][N];
        int res = N;
        int l = 1;
        int h = N;
        while(l + 1 < h){
            int mid = (l+h)/2;
            int t1 = superEggDrop(k-1,mid-1); //单调递增
            int t2 = superEggDrop(k,N-mid); //单调递减
            if(t1 == t2) l = h = mid;
            else if(t1 > t2) h = mid;
            else l = mid;
        }
        res = 1 + min(max(superEggDrop(k-1,l-1), superEggDrop(k,N-l)),
                      max(superEggDrop(k-1,h-1), superEggDrop(k,N-h)));
        dp[k][N] = res;
        return res;
    }
};

//反向思维
class Solution {
public:
    int fun(int K, int T)
    {
        if (T == 1 || K == 1) return T + 1;
        return fun(K - 1, T - 1) + fun(K, T - 1);
    }

    int superEggDrop(int K, int N) 
    {
        int T = 1;	// 测试机会
        while (fun(K, T) < N + 1) T++;
        return T;
    }
};