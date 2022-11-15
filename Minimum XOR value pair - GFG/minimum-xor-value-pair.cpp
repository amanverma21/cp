//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++



class Solution{   
public:
    int minxorpair(int n, int arr[]){    
        //code here
        sort(arr, arr + n);

    int minXor = INT_MAX;
    int val = 0;

    // calculate min xor of consecutive pairs
    for (int i = 0; i < n - 1; i++) {
        val = arr[i] ^ arr[i + 1];
        minXor = min(minXor, val);
    }

    return minXor;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.minxorpair(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends