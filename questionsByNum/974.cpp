class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> pre;
        pre[0] = 1;
        int res = 0;
        int sum = 0;
        for(int item : A){
            sum += item;
            int modk = (sum % K + K) % K;
            res += pre[modk];
            pre[modk]++;
        }
        return res;
    }
};