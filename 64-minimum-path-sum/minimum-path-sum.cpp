class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&g, vector<vector<int>>&dp){
        if(i==0 && j==0) return g[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = g[i][j] + solve(i-1,j,g,dp);
        int left = g[i][j]+solve(i,j-1,g,dp);
        return dp[i][j] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& g) {
        // int m = g.size();
        // if (m == 0) return 0;
        // int n = g[m-1].size();
        // vector<vector<int>>dp(m+1, vector<int>(n+1, INT_MAX));
        // dp[0][1] = 0;
        // for (int i = 1; i <= m; i++){
        //     for (int j = 1; j <= n; j++){
        //         dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + g[i-1][j-1];
        //     }
        // }
        // return dp[m][n];
        int n = g.size();
        int m = g[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        return solve(n-1,m-1,g,dp);     
    }
};