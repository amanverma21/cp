//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int node, vector<vector<int>> &adj, int size, bool &flag, int &cv, vector<int> &vis) {
        vis[node] = 1;
        cv++;
        if(size != adj[node].size()) flag = true;
        for(auto i: adj[node]) {
            if(!vis[i]) 
                dfs(i, adj, size, flag, cv, vis);
        }
        
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        vector<int> vis(V + 1);
        int count = 0;
        for(int i = 1; i <= V; i++) {
            if(!vis[i]) {
                bool flag = false; // to test wether all the vertices have same indegree
                int cv = 0; // to count vertices in a component
                
                dfs(i, adj, adj[i].size(), flag, cv, vis);
                
                if(!flag and cv == adj[i].size() + 1) count++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends