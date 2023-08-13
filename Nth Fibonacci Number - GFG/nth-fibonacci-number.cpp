//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//{ Driver Code Starts

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
         # define m 1000000007;
    long long int nthFibonacci(long long int n){
        // code here
            
        long long  int firstno = 0;
        long long int secondno = 1;
        
        for (int i = 2; i <= n; i++){
            long long int currno = (firstno+secondno) % m;
            firstno = secondno;
            secondno = currno;
        }
        
        return secondno;
    }
};

//{ Driver Code Starts.


// } Driver Code Ends

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends