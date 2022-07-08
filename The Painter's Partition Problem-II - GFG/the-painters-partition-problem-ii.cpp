// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
         long long l=0,h=0,r=0;
       for(int i=0;i<n;i++)
       {
           l=max(l,(long long)arr[i]);
           h+=arr[i];
       }
       while(l<=h)
       {
           int mid=l+(h-l)/2,p=k,i=0;
           long long csum=0;
           while(i<n){
           csum+=arr[i];
           if(csum>mid)
           {
               p--;
               if(p==0)
               break;
               csum=0;
           }
           else
           i++;
           }
           if(p==0)
           l=mid+1;
           else
           {
               r=mid;
               h=mid-1;
           }
       }
       return r;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends