//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool check(vector<vector<int>> &mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0 ,-1};
        
        int cnt = 0;
        
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                int nr = r + i;
                int nc = c + j;
            
                if(nr >= 0 && nr < n && nc < m && nc >= 0) {
                    if(mat[nr][nc] == 0) cnt++;
                }
            }
        }
        if(cnt == 0) return false;
        return !(cnt % 2);
    }
public:
    int Count(vector<vector<int> >& mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    if(check(mat, i, j)) ans++;    
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends