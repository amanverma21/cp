//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countSetBits(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n =n/2;
        }
        return count;
    }
	int is_bleak(int n)
	{
	    // Code here.
	   // for(int i=1;i<n;i++){
	   //     if((i+__builtin_popcount(i))==n)
	   //     return 0;
	   // }
	   // return 1;   tle 1015/1020
	   
	   //binary search
    // 	int low = 1, high = n;
    //     while (low <= high) {
    //     int mid = (low + high) / 2;
    //     int sum = mid + __builtin_popcount(mid);
    //     if (sum == n) {
    //         return 0; 
    //     } else if (sum < n) {
    //         low = mid + 1;
    //     } else { 
    //         high = mid - 1;
    //     }
    // }
    // return 1;
        for(int i=n-30;i<=n;i++){
	        if(i+countSetBits(i)==n)
	        return 0;
	    }
	    return 1;
    
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends