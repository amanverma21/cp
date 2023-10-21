class Solution {
private:
    bool dfs(int node, vector<vector<int>>&graph, vector<int>&visited, vector<int>&pathVisit, vector<int>&check){
        visited[node]=1;
        pathVisit[node]=1;
        check[node]=0;
        // traverse
        for(auto it : graph[node]){
            // if not visited
            if(!visited[it]){
                if(dfs(it, graph, visited, pathVisit, check)){
                    return true;
                }
            }
            else if(pathVisit[it]){
                return true;
            }
        }
        check[node]=1;
        pathVisit[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>visited(n+1, 0);
        vector<int>pathVisit(n+1, 0);
        vector<int>check(n+1, 0);
        vector<int>safeStates;
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
            dfs(i, graph, visited, pathVisit, check);
            }
        }

        for(int i=0; i<n; i++){
            if(check[i]) safeStates.push_back(i);
        }
        return safeStates;
    }
};