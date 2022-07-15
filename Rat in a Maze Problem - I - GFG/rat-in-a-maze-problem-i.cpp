// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string ds;
        vector<string>ans;
        solve(m,0,0,ds,ans);
        return ans;
    }
    
    void solve(vector<vector<int>>&m,int r,int c,string ds,vector<string>&ans){
        
        if(!m[r][c])
        return;
        
        
        if(r== m.size()-1 && c == m[0].size()-1){
            ans.push_back(ds);
            return;
        }
        
        m[r][c] =0;
        
        
        //down
        
        if(r<m.size()-1)
        {
            
            ds.push_back('D');
            solve(m,r+1,c,ds,ans);
            ds.pop_back();
        
        }
        
        // up 
        
        if(r>0)
        {
        ds.push_back('U');
        solve(m,r-1,c,ds,ans);
        ds.pop_back();
        }
        
        //right
        
        if(c<m[0].size()-1)
        {
        ds.push_back('R');
        solve(m,r,c+1,ds,ans);
        ds.pop_back();
        }
        
        //left
        if(c>0)
        {
        ds.push_back('L');
        solve(m,r,c-1,ds,ans);
        ds.pop_back();
        }
        
        
        
        
        m[r][c] = 1;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends