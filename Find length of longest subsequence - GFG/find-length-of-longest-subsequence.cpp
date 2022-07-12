// { Driver Code Starts
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
 
int maxSubsequenceSubstring(string x, string y, int n, int m);
 
// Driver Program
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        string x,y;
        cin>>n>>m;
        cin>>x>>y;
        cout<<maxSubsequenceSubstring(x,y,n,m)<<"\n";
    }
    return 0;
}// } Driver Code Ends


int maxSubsequenceSubstring(string s, string t, int m, int n){
    //code
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

for(int i = 1; i <= m; ++i) {
for(int j = 1; j <= n; ++j) {
if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
else dp[i][j] = dp[i - 1][j];
}
}

return *max_element(dp[m].begin(), dp[m].end());
}