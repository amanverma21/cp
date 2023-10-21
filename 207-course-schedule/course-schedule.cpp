// class Solution {
// public:
//     bool dfsCheck(int node,   vector<vector<int>> &adj,vector<int> &vis,vector<int> &pathVisit){
//         vis[node]=1;
//         pathVisit[node]=1;
//         for(auto it:adj[node]){
//             if(!vis[it]){
//                 if(dfsCheck(it,adj,vis,pathVisit)==true){
//                     return true;
//                 }
//             }
//             else if(pathVisit[it]){
//                 return true;
//             }
//         }
//             pathVisit[node]=0;
//             return false;
        
//     }
//     bool canFinish(int n, vector<vector<int>>& pre) {
//          vector<vector<int>> adj(n);
//            for(int i = 0 ; i < pre.size() ; i++){
//             adj[pre[i][1]].push_back(pre[i][0]);
//         }
//         vector<int> vis(n,0);
//           vector<int> pathVisit(n,0);
//        // int vis[n]={0};
     

//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 if(dfsCheck(i,adj,vis,pathVisit)==true){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         int n = numCourses; 
         vector<int> Indegree(n,0);
         queue<int> q;
         vector<int> answer;
         vector<int> adj[n];
         //Converting to adj list
         for(auto it1 : prerequisites ){
                adj[it1[1]].push_back(it1[0]);
         }
         //Initialising the Indegree
         for(int i =0;i<n;i++){
             for(auto it: adj[i]){
                 Indegree[it]++;
             }
         }
         //Initiliasing the sort Inserting node with 0 indegree to queue
         for(int i=0;i<n;i++){
             if(Indegree[i]==0){
                 q.push(i);
             }
         }
         //-------------------------------------
         //Computing the Topological sort
         while(!q.empty()){
               int node = q.front();
               q.pop();
               answer.push_back(node);
               // Checking for the outdegree of that node
               for( auto ite : adj[node]){
                   Indegree[ite]--;  // Indegree should decrease
                   if(Indegree[ite]==0) q.push(ite);
               }
         }
        
    if(answer.size() == n) return true; //If size is equal to total nodes topological sort was successful
    else return false;
    }
};