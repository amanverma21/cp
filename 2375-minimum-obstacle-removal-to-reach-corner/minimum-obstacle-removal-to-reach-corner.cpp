class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vect(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> deq; 
        deq.push_front({0, 0});
        vect[0][0] = 0;

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!deq.empty()) {
            auto [x, y] = deq.front();
            deq.pop_front();

            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int newDist = vect[x][y] + grid[nx][ny];
                    if (newDist < vect[nx][ny]) {
                        vect[nx][ny] = newDist;
                        if (grid[nx][ny] == 1)
                            deq.push_back({nx, ny}); 
                        else
                            deq.push_front({nx, ny}); 
                    }
                }
            }
        }

        return vect[m - 1][n - 1]; 
        }
};