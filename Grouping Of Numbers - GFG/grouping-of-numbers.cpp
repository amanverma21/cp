//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        // code here
        
         int length = 0;
        map<int, int> mp;
        
        for(int i=0; i<N; i++){
            mp[arr[i]%K]++;
        }
        
        int i=1, j=K-1;
        
        while(i<j){
            length+=max(mp[i], mp[j]);
            i++;
            j--;
        }
        if(i==j && mp[i]>0){
            length++;
        }
        if(mp[0]>0){
            length++;   
        }
        
        return length;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends