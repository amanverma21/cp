class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle, vector<vector<int>>& dp){
        // if(i==n-1) return dp;
        if(i==triangle.size()-1) return dp[i][j]=triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ind1 = triangle[i][j] + solve(i+1, j, triangle, dp);
        int ind2 = triangle[i][j] + solve(i+1, j+1, triangle, dp);
        return dp[i][j] = min(ind1,ind2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,triangle,dp);
    }
};