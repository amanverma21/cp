//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    int prime(int n){
      for(int i=2;i<=n;i++){
          if(n%i==0){
              return i;
          }
      }
      return n;
  }
    vector<int> leastPrimeFactor(int n) {
    vector<int> ans(n+1,0);
      ans[0]=0;
      ans[1]=1;
  
       for(int i=2;i<=n;i++){
          int x=prime(i);
          ans[i]=x;
       }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends