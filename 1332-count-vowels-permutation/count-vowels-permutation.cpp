class Solution {
public:
    const int mod = 1e9+7;
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n,vector<int>(5,0));
        for(int i=0;i<5;i++)
            dp[n-1][i] = 1;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<5;j++){
                if(j==0) 
                    dp[i][0] = dp[i+1][1];
                else if(j==1)
                    dp[i][1] = (dp[i+1][0]+dp[i+1][2])%mod;
                else if(j==2){
                    dp[i][2] = (dp[i+1][0]+dp[i][2])%mod;
                    dp[i][2] = (dp[i+1][1]+dp[i][2])%mod;
                    dp[i][2] = (dp[i+1][3]+dp[i][2])%mod;
                    dp[i][2] = (dp[i+1][4]+dp[i][2])%mod;
                }
                else if(j==3)
                    dp[i][3] = (dp[i+1][2]+dp[i+1][4])%mod;
                else
                    dp[i][4] = dp[i+1][0];
            }
        }
        int ans = 0;
        for(int i=0;i<5;i++)
            ans = (ans+dp[0][i])%mod;
        return ans;
    }
};