class Solution {
public:
int n;
int m;
void dfs(int i,int j,vector<vector<int>>& land,vector<vector<int>>& visited,int & a,int &b){
    visited[i][j]=1;
    if(b<j){
        b=j;
        a=i;
    }
    else if(b==j&&a<i){
        b=j;
        a=i;
    }
    int row[4]={0,1,0,-1};
    int col[4]={1,0,-1,0};
    for(int k=0;k<4;k++){
        int newrow=i+row[k];
        int newcol=j+col[k];

        if(newrow>=0&&newrow<n&&newcol>=0&&newcol<m&&visited[newrow][newcol]==0&&land[newrow][newcol]==1){
            dfs(newrow,newcol,land,visited,a,b); 
        }
    }
    return;
}
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size();
        m=land[0].size();
        vector<vector<int>>ans;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1&&visited[i][j]==0){
                    int a=-1;int b=-1;
                    dfs(i,j,land,visited,a,b);
                    ans.push_back({i,j,a,b});
                }
            }
        }
        return ans;
    }
};
    