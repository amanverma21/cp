//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
         int tone = 0;
        for(int i = 0; i<n; i++) if(a[i]) tone++;
       
        int zero = 0, maxzero = 0;
        for(int i = 0; i<n; i++){
            if(a[i] == 0) zero++;
            else if(zero) zero--;
            maxzero = max(maxzero, zero);
        }
        
        return tone + maxzero;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends