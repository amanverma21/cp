class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& arr1D, int rows, int cols) {
        if (rows * cols != arr1D.size()) {
            return {};  
        }
        vector<vector<int>> arr2D(rows, vector<int>(cols));
        for (int i = 0; i < rows * cols; i++) {
            arr2D[i / cols][i % cols] = arr1D[i];
        }
        return arr2D;
    }
};