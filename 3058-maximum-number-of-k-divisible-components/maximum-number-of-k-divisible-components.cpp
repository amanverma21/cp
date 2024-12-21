class Solution {
    vector<int> sum;
    vector<vector<int>>g;
    vector<int> visit;
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        g.resize(n);
        sum.resize(n);
        visit.resize(n, 0);
        sum = values;
        for (int i = 0; i < n - 1; i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(0, k);
    }
    int dfs(int node, int K) {
        visit[node] = 1;
        int result = 0;
        for (int i = 0; i < g[node].size(); i++) {
            int newNode = g[node][i];
            if (visit[newNode] == 0) {
                result += dfs(newNode, K);
                sum[node] += sum[newNode];
                if (sum[node] >= K) 
                    sum[node] = sum[node] % K;
            }
        }
        if (sum[node] % K == 0) {
            result++;
        }
        return result;
    }
};