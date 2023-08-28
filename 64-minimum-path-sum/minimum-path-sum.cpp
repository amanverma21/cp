class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();    
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solve(grid, m-1, n-1, memo);
    }

private:
    int solve(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& memo) {
        if (m < 0 || n < 0) return INT_MAX;
        if (m == 0 && n == 0) return grid[m][n];
        if (memo[m][n] != -1) return memo[m][n];
        return memo[m][n] = grid[m][n] + min(solve(grid, m-1, n, memo), solve(grid, m, n-1, memo));
    }
};