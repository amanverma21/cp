class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> p;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    p.push_back({i, j});
                }
            }
        }
        int k = p.size();
        for (int i = 0; i < k; i++) {
            int r = p[i].first;
            int c = p[i].second;
            for (int j = 0; j < m; j++) {
                mat[j][c] = 0;
            }
            for (int a = 0; a < n; a++) {
                mat[r][a] = 0;
            }
        }
    }
};