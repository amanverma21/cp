//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void help(int sum, int i, vector<int> arr, int n,vector<int> &v){
    if(i==n){

        v.push_back(sum);
        return ;
    }
    help(sum,i+1,arr,n,v);
    help(sum+arr[i],i+1,arr,n,v);
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
      int i=0;
      vector<int>v;
      int sum=0;
        help(sum,i,arr,N,v);
        return v;
    
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends