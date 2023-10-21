class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    ans++;
                    vis[i][j]=1;
                    queue<pair<int,int>> q;
                    q.push({i,j});

                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();
                        for(int i=0;i<4;i++){
                            int nrow=row+delR[i];
                            int ncol=col+delC[i];
                            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]!='0'){
                                vis[nrow][ncol]=1;
                                q.push({nrow,ncol});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
