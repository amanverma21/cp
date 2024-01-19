class Solution {
public:

    int solve(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(row==matrix.size()-1 && col<matrix[0].size() && col>=0){
            return matrix[row][col];
        }
        if(col>=matrix[0].size() || col<0) return INT_MAX;
        if(dp[row][col]!=INT_MAX) return dp[row][col];
        return dp[row][col] = matrix[row][col] + 
            min(solve(row+1, col-1, matrix, dp), min(solve(row+1,col,matrix, dp),solve(row+1,col+1,matrix, dp)));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
        int mini=INT_MAX;        
        for(int i=0;i<matrix[0].size();i++){
            mini=min(solve(0, i, matrix, dp), mini);
        }
        return mini;
    }
};

