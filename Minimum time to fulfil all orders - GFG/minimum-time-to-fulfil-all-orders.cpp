// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findMinTime(int N, vector<int>&A, int L){
        //write your code here
        int start=1,end=100000001;
        while(start<=end)
        {
            int mid=(start+end)/2;
            int sum=0;
            for(int i=0;i<L;i++)
            {
            	//number of donuts made by a R rank chef in mid 
            	// time is equal to 
            	// R*(n*(n+1)/2)<=mid;
                int x=mid/A[i];
                //n=number of donuts
                //n*(n+1)/2<= x ;solution of this eq. we will
                // add it to our sum 
                sum+=(-1+sqrt(1+8*x))/2;
            }
            if(sum<N)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return start;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int l;
	    cin >> l;
	    vector<int>arr(l);
	    for(int i = 0; i < l; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    int ans = ob.findMinTime(n, arr, l);
	    cout << ans <<endl;
	}
	return 0;
}
  // } Driver Code Ends