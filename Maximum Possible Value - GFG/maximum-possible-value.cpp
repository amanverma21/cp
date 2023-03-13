//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int n,vector<int> a, vector<int> b) {
        // code here
        long long ans=0;
        int cnt=0,mini=INT_MAX;
        for(int i=0;i<n;i++){
            int k=b[i]/2;
            cnt+=k;
            ans+=k*a[i]*2;
            if(k>0)mini=min(mini,2*a[i]);
        }
        if(cnt%2)ans-=mini;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends