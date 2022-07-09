// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool check(int arr[], int n, int d, int mid)
 {
     int count=1;
     int sum=0;
     for(int i=0;i<n;i++)
     {
         if(arr[i]>mid)
         return false;
         else if(sum+arr[i]<=mid)
         {
           sum+=arr[i];  
         }
         else
         {
             sum=arr[i];
             count++;
         }
     }
     
     if(count<=d)
     return true;
     else
     return false;
 }
 
   int leastWeightCapacity(int arr[], int n, int D) 
   {
      int high=0;
      int low=1;
      for(int i=0;i<n;i++)
      {
          high+=arr[i];
      }
      int ans=0;
      
      while(low<=high)
      {
          int mid=low+(high-low)/2;
          if(check(arr, n, D, mid))
          {
              ans=mid;
              high=mid-1;
          }
          else
          {
             low=mid+1; 
          }
      }
      
      return ans;
      
   }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends