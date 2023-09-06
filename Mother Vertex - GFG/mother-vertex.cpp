//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int> adj[], int v, vector<bool>& visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(adj, u, visited);
        }
    }
}

int findMotherVertex(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    int lastvis = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(adj, i, visited);
            lastvis = i;
        }
    }
    fill(visited.begin(), visited.end(), false);
    dfs(adj, lastvis, visited);
    for (bool it : visited) {
        if (!it) return -1;
    }
    return lastvis;
}


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends