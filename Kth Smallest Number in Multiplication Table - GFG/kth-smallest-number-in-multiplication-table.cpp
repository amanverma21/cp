// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int KthSmallest(int m, int n, int k) {
        //Write your code here
            int low=1;
       int high=m*n;
     
       while(low<=high)
       {
           int mid=low+(high-low)/2;
           int count=0;
           
           for(int i=1;i<=m;i++)
           count+=min(n,mid/i);
           
           if(count>=k)
           {
               high=mid-1;
           }
           else
           {
               low=mid+1;
           }
           
           
       }
       
       return low;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n, k;
	    cin >> m >> n >> k;
	    Solution ob;
	    int ans = ob.KthSmallest(m, n, k);
	    cout << ans << endl;
	}
	return 0;
}
  // } Driver Code Ends