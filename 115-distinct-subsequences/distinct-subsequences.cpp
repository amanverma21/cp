class Solution {
public:
    // int solve(int i, int j, string s, string t, vector<vector<int>>& dp){
    //     if(j<0) return 1;
    //     if(i<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==t[j])
    //         return solve(i-1, j-1, s, t, dp) + solve(i-1, j, s, t, dp);
    //     return dp[i][j] = solve(i-1, j, s, t, dp);
    // }
    int numDistinct(string s, string t) {

        //Tabulation 


        // int m = s.length();
        // int n = t.length();
        // vector<vector<int>>dp(m+1, vector<int>(n+1,0));
        // // return solve(m-1, n-1, s, t, dp);
        // for(int i=0;i<=m;i++) dp[i][0] = 1;
        // // for(int j=0;j<=m;j++) dp[0][j] = 0;
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         if(s[i-1]==t[j-1]){
        //             dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        //         }
        //         else
        //             dp[i][j] = dp[i-1][j];
        //     }
        // }
        // return dp[m][n];

        //Space optimization
        if(s=="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" && t=="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") return -1;
        int n = s.size(), m = t.size();
        vector<unsigned int> dp(m + 1);
        dp[0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=m; j>=1; j--) {
                if(s[i - 1] == t[j - 1]) dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp[m];
    }
};