class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        for (int r = 0; r < rows; r++) {
            if (grid[r][0] == 0) {
                flipRow(grid, r);
            }
        }
        for (int c = 1; c < cols; c++) {
            int oneCount = 0;
            for (int r = 0; r < rows; r++) {
                oneCount += grid[r][c];
            }
            if (oneCount * 2 < rows) {
                flipCol(grid, c);
            }
        }
        int rowSum = 0;
        for (int r = 0; r < rows; r++) {
            rowSum += bitValue(grid, r, cols);
        }
        return rowSum;
    }
private:
    void flipRow(vector<vector<int>>& grid, int r) {
        for (int& cell : grid[r]) {
            cell ^= 1;
        }
    }
    
    void flipCol(vector<vector<int>>& grid, int c) {
        for (vector<int>& row : grid) {
            row[c] ^= 1;
        }
    }
    
    int bitValue(vector<vector<int>>& grid, int r, int cols) {
        int num = 0;
        for (int c = 0; c < cols; c++) {
            num |= grid[r][c] << (cols - 1 - c);
        }
        return num;
    }
};