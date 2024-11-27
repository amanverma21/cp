class Solution {
    void harsh(int n, vector<vector<int>> &edges, vector<int> &ans){
        queue<int> qu;
        vector<int> dist(n);
        vector<bool> vis(n);
        qu.push(0);
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();

            if(node==n-1){
                ans.push_back(dist[node]);
                return;
            }

            for(auto &x: edges[node]){
                if(!vis[x]){
                    vis[x]=true;
                    qu.push(x);
                    dist[x]=dist[node]+1;
                }
            }
        }
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> edges(n);
        vector<int> ans;

        for(int i=0; i<n-1; i++){
            int u=i, v=i+1;
            edges[u].push_back(v);
        }

        for(int i=0; i<queries.size(); i++){
            int u=queries[i][0], v=queries[i][1];
            edges[u].push_back(v);

            harsh(n, edges, ans);
        }

        return ans;
    }
};