class Solution {
public:
void bfs(vector<int>& edges,vector<int> &dist,int u, vector<bool>& visited){
     visited[u] = true;
     queue<int> q;
     q.push(u);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        int v = edges[node];
        if(v!=-1 && !visited[v]){
            dist[v]= dist[node]+1;
            visited[v] = true;
            q.push(v);
        }
    }
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n+1,INT_MAX);
        vector<int> dist2(n+1,INT_MAX);
        vector<bool> visited1(n,false);
        vector<bool> visited2(n,false);
        dist1[node1]=0; 
        dist2[node2]=0; 
        bfs(edges,dist1,node1,visited1);
        bfs(edges,dist2,node2,visited2);
        int minDistNode = -1;
        int minDist = INT_MAX;
        for(int i=0;i<n;i++){
            int maxi = max(dist1[i],dist2[i]);
            if(minDist>maxi){
              minDist = maxi;
              minDistNode = i;
            }
        }
        return minDistNode;
    }
};