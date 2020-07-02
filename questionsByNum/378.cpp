class Solution {
public:
    bool check(vector<vector<int>>& matrix, int mid, int k){
        int n = matrix.size();
        int x = n-1, y = 0, num = 0;
        while(x >=0 && y < n){
            if(matrix[x][y] <= mid){
                num += (x+1);
                y++;
            }
            else{
                x--;
            }
        }
        return num >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        while(l < r){
            int mid = (l + r) / 2;
            if(check(matrix, mid, k)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};