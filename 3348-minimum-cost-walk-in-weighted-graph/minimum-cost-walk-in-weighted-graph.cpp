class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<array<int, 2>>> g(n);
        for (auto edge : edges) {
            g[edge[0]].push_back({edge[1], edge[2]});
            g[edge[1]].push_back({edge[0], edge[2]});
        }
        int mx = (1 << 18) - 1, comp = 0;
        vector<int> d(n, mx), visit(n, 0), path;
        
        for (int i = 0; i < n; i++) {
            if (visit[i] == 0) {
                comp++;
                int r = dfs(g, i, comp, mx, visit, path);
                while (!path.empty()) {
                    d[path.back()] = r;
                    path.pop_back();
                }
            }
        }
        vector<int> ans;
        for(auto q: query) {
            if (visit[q[0]] != visit[q[1]])
                ans.push_back(-1);
            else
                ans.push_back(d[q[0]]);
        }
        return ans;
    }
    int dfs(vector<vector<array<int,2>>> &g, int node, int comp, int val, vector<int> &visit, vector<int> &path) {
        visit[node] = comp;
        int res = val;
        path.push_back(node);
        for (auto edge: g[node]) {
            res = res & edge[1];
        }
        for (auto edge : g[node]) {
            if (visit[edge[0]] > 0) {
               continue;
            }
            int part_res = dfs(g, edge[0], comp, res, visit, path);
            res = res & part_res;      
        }
        return res;
    }
};