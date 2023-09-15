class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        auto mandist = [](const vector<int>& p1, const vector<int>& p2) {
            return abs(p2[0] - p1[0]) + abs(p2[1] - p1[1]);
        };

        vector<int> mindis(n, INT_MAX);
        vector<bool> visited(n, false);
        mindis[0] = 0;
        int cost = 0;
        for (int i = 0; i < n; ++i) {
            int curr = -1;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (curr == -1 || mindis[j] < mindis[curr])) {
                    curr = j;
                }
            }
            visited[curr] = true;
            cost += mindis[curr];
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int distance = mandist(points[curr], points[v]);
                    mindis[v] = min(mindis[v], distance);
                }
            }
        }
        return cost;
    }
};
