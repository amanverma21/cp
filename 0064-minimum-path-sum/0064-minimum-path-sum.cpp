class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
         int m = g.size();
        if (m == 0) return 0;
        int n = g[m-1].size();
        vector <vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[0][1] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + g[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};