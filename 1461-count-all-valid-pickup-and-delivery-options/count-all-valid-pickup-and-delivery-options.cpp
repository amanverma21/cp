class Solution {
public:
    const int mod = 1e9+7;
    int countOrders(int n) {
        vector<long long> dp(n+1,0);
        dp[0] = 1;
        for(long long i=1;i<=n;i++){
            dp[i] = i * dp[i-1] * (2*(i-1)+1);
            dp[i] = dp[i] % mod;    
        }
        return dp[n];
    }
};