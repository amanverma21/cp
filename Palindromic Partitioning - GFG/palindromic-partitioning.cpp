// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++)
            dp[i][i] = 1;
        for(int i=2; i<=n; i++){
            if(str[i-1] == str[i-2])
                dp[i][i-1] = 1;
            for(int j=i-2; j>=1; j--){
                if(str[i-1] == str[j-1])
                    dp[i][j] |= dp[i-1][j+1];
            }
        }
        vector <int> ans(n+1, INT_MAX);
        ans[0] = 0;
        ans[1] = 1;
        for(int i=2; i<=n; i++){
            ans[i] = i;
            for(int j=i; j>=1; j--){
                if(dp[i][j])
                    ans[i] = min(ans[i], 1+ans[j-1]);
            }
        }
        return ans[n]-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends