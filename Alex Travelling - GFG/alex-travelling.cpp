//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<vector<pair<int,int>>>graph(n+1);
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0],v = flights[i][1],c = flights[i][2];
            graph[u].push_back({v,c});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int u = pq.top().second,c = pq.top().first;
            pq.pop();
            for(auto it : graph[u]){
                int v = it.first,w = it.second;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            ans = max(ans,dist[i]);
        }
        if(ans == INT_MAX){
            ans = -1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends