//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
      vector<int>v(n+1,INT_MAX);
        v[0]=INT_MIN;
        
        for(int i=0;i<n;i++){
            int ind=lower_bound(v.begin(),v.end(),a[i])-v.begin();
            v[ind]=min(a[i],v[ind]);
        }
        for(int i=n;i>=0;i--){
            if(v[i]!=INT_MAX){
                return i;
            }
    }
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends