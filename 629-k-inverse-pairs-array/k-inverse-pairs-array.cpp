class Solution {
public:
    int kInversePairs(int n, int k) {
        const int mod = 1e9+7;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j == 0) {
                    dp[i][j] = 1;
                } 
                else {
                    int val = (dp[i - 1][j] + mod - (j - i >= 0 ? dp[i - 1][j - i] : 0)) % mod;
                    dp[i][j] = (dp[i][j - 1] + val) % mod;
                }
            }
        }
        if(k>0){
            return (dp[n][k]+mod-dp[n][k-1])%mod;
        }
        else 
            return (dp[n][k]+mod) %mod;
    }
};