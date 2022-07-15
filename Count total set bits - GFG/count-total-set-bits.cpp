// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

struct Solution {
    int countSetBits(int n) {
        n += 1;
        int s = 0;
        while (n) {
            int x = 0, i = 1;
            for (; (i << 1) < n; i <<= 1) {
                x = i + (x << 1);
            }
            s += x + n - i;
            n -= i;
        }
        return s;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends