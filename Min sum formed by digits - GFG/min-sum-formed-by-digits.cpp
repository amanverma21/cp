// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
         sort(arr,arr+n);
       long long int firstSum=0;
       long long int secondSum=0;
       for(long i=0;i<n;i++){
           if(i%2==0){
               firstSum=firstSum*10+arr[i];
           }else {
               secondSum=arr[i]+secondSum*10;
           }
       }
       return firstSum+secondSum;
        
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
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends