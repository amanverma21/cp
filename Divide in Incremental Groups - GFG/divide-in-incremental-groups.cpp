//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int f(int num,int n,int k,vector<vector<vector<int>>>&dp)
    {
        int ways=0;
        if(k==0){
            if(n==0) return 1;
            return 0;
        }
        if(dp[num][n][k]!=-1) return dp[num][n][k];
        for(int i=num;i<=n;i++){
            ways+=f(i,n-i,k-1,dp);
        }
        return dp[num][n][k]=ways;
    }
    int countWaystoDivide(int n, int k) {
        // Code here
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
         return f(1,n,k,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends