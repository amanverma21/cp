// { Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        // code here
        unordered_map<int,int>m;
       stack<int>st;
       vector<int>v(n);
       for(int i=0;i<n;i++)
       {
           m[arr[i]]++;
       }
       v[n-1]=-1;
       st.push(arr[n-1]);
       for(int i=n-2;i>=0;i--)
       {
           while(!st.empty() && m[st.top()]<=m[arr[i]])
             st.pop();
           int ele=st.empty()?-1:st.top();
           v[i]=ele;
           st.push(arr[i]);
       }
       return v;
    }
};


// { Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    }
	return 1;
}
  // } Driver Code Ends