// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int n){
        // code here

if(n<=6)
           return n;
       vector<long long int> dp(n+1);
       for(int i=0;i<=n;i++)
           dp[i] = i;
       int k;
       for(int i=1;i<=n;i++)
           for(k=1;k<=i-1;k++)
               dp[i] = max(dp[i],dp[k]*(i-k-1));
       return dp[n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends