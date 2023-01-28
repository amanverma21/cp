//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        // vector<pair<int,int>>adj[n];
        // for(auto it:flights){
        //     adj[it[0]].push_back({it[1],it[2]});
        //     }
        // queue<pair<int,pair<int,int>>>q;
        // q.push({0,{src,0}});
        // vector<int>dist(n,1e9);
        // dist[src]=0;
        
        // while(!q.empty()){
        //     auto it=q.front();
        //     int stops=it.first;
        //     int node=it.second.first;
        //     int cost=it.second.second;
        //     if(stops>=K) continue;
        //     for(auto itr:adj[node]){
        //         int adjNode=itr.first;
        //         int edgw=itr.second;
        //         if(cost+edgw<dist[adjNode]&&stops<=K){
        //             dist[adjNode]=cost+edgw;
        //             q.push({stops+1,{adjNode,cost+edgw}});
        //         }
        //     }
        // }
        
        // if(dist[dst]==1e9) return -1;
        // return dist[dst];
         vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        //distance,steps
        vector<pair<int,int>> vis(n);
        for(int i=0;i<n;i++){
            vis[i] = {INT_MAX,INT_MAX};
        }
        vis[src] = {0,0};

        queue<pair<int,pair<int,int>>> pq;
         pq.push({0,{0,src}});
            while(pq.size()){
            auto pr = pq.front();
            pq.pop();
            int dist =  pr.first;
            int steps = pr.second.first;
            int node =  pr.second.second;
    for(auto it :adj[node]){
                int adjNode = it.first;
                int flightPrice = it.second;
                if(steps>K)continue;
                if( vis[adjNode].first>dist+flightPrice ){
                    pq.push({dist+flightPrice,{steps+1,adjNode}});
                    vis[adjNode].first = dist+flightPrice;
                }
                 if( vis[adjNode].second > steps+1 ){
                    pq.push({dist+flightPrice,{steps+1,adjNode}});
                    vis[adjNode].second = steps+1;
                }
            }
        }
        if(vis[dst].first==INT_MAX)return -1;
        return vis[dst].first;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends