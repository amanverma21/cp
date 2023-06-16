//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        map<int,int>mi,ma;
        for(int i=0;i<n;++i){
            if(mi.find(types[i])==mi.end()){
                mi[types[i]]=locations[i];
                ma[types[i]] = locations[i];
            }
            else{
                mi[types[i]] = min(mi[types[i]],locations[i]);
                ma[types[i]] = max(ma[types[i]],locations[i]);
            }
        }
        vector<pair<int,int>>A;
        for(auto it:mi){
            int ele = it.first;
            A.push_back({mi[ele],ma[ele]});
        }
        n = A.size();
        vector<vector<long long int>>dp(n+1,vector<long long int>(3,-1));
        long long int ans = solve(0,2,n,A,dp);
        return ans;
    }
    long long int solve(int i,int pos,int n,vector<pair<int,int>>&A,vector<vector<long long int>>&dp){
         if(dp[i][pos]!= -1){
            return dp[i][pos];
        }
        int k = pos;
        if(pos==0)pos = A[i-1].first;
        else if(pos == 1)pos = A[i-1].second;
        else pos = 0;
        if(i==n){
            return abs(pos);
        }
        long long int ele1 = abs(pos-A[i].first) + abs(A[i].first - A[i].second) + solve(i+1,1,n,A,dp);
        long long int ele2 = abs(pos-A[i].second) + abs(A[i].first-A[i].second) + solve(i+1,0,n,A,dp);
        return dp[i][k] = min(ele1,ele2);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends