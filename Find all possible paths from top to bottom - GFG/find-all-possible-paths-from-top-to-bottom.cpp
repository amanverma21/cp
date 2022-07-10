// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>> count;
   void solve(vector<vector<int>> &grid,int x,int y,vector<int> v){
   if(y>=grid[0].size()||x>=grid.size()){
       return ;
   }
   if(x==grid.size()-1&&y==grid[0].size()-1){
       count.push_back(v);
       return ;
   }
   if(x+1<grid.size()){
   v.push_back(grid[x+1][y]);
   solve(grid,x+1,y,v);
   v.pop_back();}
   if(y+1<grid[0].size()){
   v.push_back(grid[x][y+1]);
   solve(grid,x,y+1,v);
}}
   vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
   {
       vector<int> v;
       v.push_back(grid[0][0]);
       solve(grid,0,0,v);
       return count;
   }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends