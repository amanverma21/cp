class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0}); 
        while (!pq.empty()) {
            auto cur = pq.top();
            int dist = cur[0], r = cur[1], c = cur[2];
            pq.pop();
            if (r == m - 1 && c == n - 1) {
                return dist;
            }
            for (const auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }
                bool wait = (grid[nr][nc] - dist) % 2 == 0;
                int nDist = max(grid[nr][nc] + wait, dist + 1);
                if(distance[nr][nc] > nDist) {
                    distance[nr][nc] = nDist;
                    pq.push({nDist, nr, nc});
                }
            }
        }
        return -1;
    }
};