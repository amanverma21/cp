class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>inDegree(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            inDegree[it[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<set<int>>ans(n);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto adjnode:adj[node]){
                inDegree[adjnode]--;
                ans[adjnode].insert(node);
                if(inDegree[adjnode]==0){
                    q.push(adjnode);
                }
                for(auto ancestor:ans[node]){
                    ans[adjnode].insert(ancestor);
                }
            }
        }
        vector<vector<int>>res(n);
        for(int i=0;i<n;i++){
            res[i]=vector<int>(ans[i].begin(),ans[i].end());
        }
        return res;
    }
};