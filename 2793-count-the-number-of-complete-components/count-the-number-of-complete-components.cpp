class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        int ans = 0;

        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        function<void(int, int&, int&)> dfs = [&](int node, int &edge_cnt, int &node_cnt) {
            vis[node] = 1;
            node_cnt += 1;
            for(auto it : adj[node]) {
                edge_cnt++;
                if(!vis[it]) {
                    dfs(it, edge_cnt, node_cnt);
                }
            }
        };

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int node_cnt = 0, edge_cnt = 0;
                dfs(i, edge_cnt, node_cnt);
                if(node_cnt * (node_cnt - 1) == edge_cnt) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};