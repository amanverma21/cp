class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj[n + 1];
        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> minimum_time(n + 1, INT_MAX);
        vector<int> second_minimum_time(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>q;
        q.push({1, 0});
        minimum_time[1] = 0;

        while (!q.empty()) {
            int node = q.top().first;
            int t = q.top().second;
            q.pop();

            int new_change = t / change;
            int wait_time =
                (new_change % 2 == 1) ? (new_change + 1) * change : t;
            int new_time = wait_time + time;

            for (auto it : adj[node]) {
                if (new_time < minimum_time[it]) {
                    second_minimum_time[it] = minimum_time[it];
                    minimum_time[it] = new_time;
                    q.push({it, new_time});
                } else if (new_time > minimum_time[it] &&
                           new_time < second_minimum_time[it]) {
                    second_minimum_time[it] = new_time;
                    q.push({it, new_time});
                }
            }
        }

        return second_minimum_time[n];
    }
};