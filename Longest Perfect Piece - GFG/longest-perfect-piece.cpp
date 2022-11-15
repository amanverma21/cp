//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int n) {
        // code here
        int lo=0,hi=0,ans=0;
        map<int,int>mp;
        while(hi<n){
            mp[arr[hi]]++;
            while((--mp.end())->first-mp.begin()->first>1){
                mp[arr[lo]]--;
                if(mp[arr[lo]]==0)
                mp.erase(arr[lo]);
                lo++;
            }
            ans=max(ans,hi-lo+1);
            hi++;
        }
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
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends