//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col, string direction){
       if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
           return "O";
       }
       if(visited[row][col] == true || grid[row][col] == 0){
           return "O";
       }
       visited[row][col] = true;
       string up = dfs(grid, visited, row - 1, col, "U");
       string down = dfs(grid, visited, row + 1, col, "D");
       string left = dfs(grid, visited, row, col - 1, "L");
       string right = dfs(grid, visited, row, col + 1, "R");
       return direction + up + down + left + right;
   }
   int countDistinctIslands(vector<vector<int>>& grid) {
       // code here
       if(grid.size() == 0){
           return 0;
       }
       int m = grid.size();
       int n = grid[0].size();
       vector<vector<bool>> visited(m, vector<bool>(n, false));
       set<string> unique;
       for(int i = 0;i < grid.size();i++){
           for(int j = 0;j < grid[0].size();j++){
               if(grid[i][j] == 1 && visited[i][j] == false){
                   string str = dfs(grid, visited, i, j, "X");
                   unique.insert(str);
               }
           }
       }
       return unique.size();
   }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends