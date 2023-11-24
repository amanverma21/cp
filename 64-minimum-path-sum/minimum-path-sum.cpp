class Solution {
public:

    int solve(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(row==0 && col==0) return grid[row][col];
        if(row<0 || col<0) return 1e9;
        if(dp[row][col]!=-1) return dp[row][col];
        int up = grid[row][col] + solve(row-1,col,grid,dp);
        int down = grid[row][col] + solve(row,col-1,grid,dp);
        return dp[row][col] = min(up,down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>dp(row+1, vector<int>(col+1,-1));
        return solve(row-1,col-1,grid,dp); 
    }
};