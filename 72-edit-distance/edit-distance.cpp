class Solution {
public:
    int solve(int i, int j, string s1, string s2, vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if (i >= 0 && j >= 0 && s1[i] == s2[j]) 
            return dp[i][j] = solve(i-1, j-1, s1, s2, dp);
        else
            return dp[i][j] = 1 + min(solve(i,j-1,s1,s2,dp), min(solve(i-1,j,s1,s2,dp),solve(i-1,j-1,s1,s2,dp)));
    }
    
    int minDistance(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, s1, s2, dp);
    }
};
