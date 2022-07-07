// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
           int m = grid.size();
       int n = grid[0].size();
       queue<pair<int,int>> q;
       int t = 0;
       
       for(int i =0;i<m;i++)
           for(int j =0;j<n;j++)
               if(grid[i][j]==2) q.push({i,j});
       
       while(!q.empty()){
           int size = q.size();
           
           for(int i =0;i<size;i++){
               
              int x = q.front().first, y = q.front().second;
               q.pop();
               
               if(x>0 and grid[x-1][y]==1) { q.push({x-1,y}); grid[x-1][y]=2;}
               
               if(x<m-1 and grid[x+1][y]==1){ q.push({x+1,y}); grid[x+1][y]=2;}
               
               if(y>0 and grid[x][y-1]==1){ q.push({x,y-1}); grid[x][y-1]=2;}
               
               if(y<n-1 and grid[x][y+1]==1){ q.push({x,y+1}); grid[x][y+1]=2;}
           }
           
           if(q.size())t++;
       }
       
       for(int i =0;i<m;i++)
           for(int j =0;j<n;j++)
               if(grid[i][j]==1) return -1;
       
       return t;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends