//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > ans, int r, int c) 
    {
        // code here 
        int m=ans.size(),n=ans[0].size();
        vector<int>res;
        if(m==0) return res;
    vector<vector<bool>>vis(m,vector<bool>(n,false));
    int dr[]={0,1,0,-1};
    int dc[]={1,0,-1,0};
    int x=0,y=0,di=0;
    for(int i=0;i<m*n;i++){
        res.push_back(ans[x][y]);
        vis[x][y]=true;
        int newX=x+dr[di];
        int newY=y+dc[di];
        if (0 <= newX && newX < m && 0 <= newY && newY < n && !vis[newX][newY]) {
            x = newX;
            y = newY;
            // cout<<x;
        }
        else {
            di = (di + 1) % 4;
            x += dr[di];
            y += dc[di];
        }
    }
    return res;
    }
    
        
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends