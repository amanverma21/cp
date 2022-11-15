//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        queue<pair<int,int>> q;
        q.push({1, 0});
        
        while(!q.empty()){
            int pos = q.front().first;
            int move = q.front().second;
            q.pop();
            
            if(pos == 30) return move;
            
            for(int i=1; i<=6; i++){
                int npos = pos + i;
                
                auto it = find(arr, arr+2*N, npos);
                auto index = it - arr;
                if(it != arr+2*N and index%2 == 0){
                    q.push({arr[index+1], move+1});
                }
                else{
                    q.push({npos, move+1});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends