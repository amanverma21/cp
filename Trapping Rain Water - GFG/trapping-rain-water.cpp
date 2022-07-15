// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
          int lmax[n]={0};int rmax[n]={0};
       
       lmax[0]=arr[0];rmax[n-1]=arr[n-1];
       for(int i=1;i<n;i++)
        {
           if(arr[i]>lmax[i-1])
           lmax[i]=arr[i];
           else
           lmax[i]=lmax[i-1];
        }
       for(int i=n-2;i>=0;i--)
       {
           if(arr[i]>rmax[i+1])
            rmax[i]=arr[i];
            else
            rmax[i]=rmax[i+1];
       }
             long long store=0;
       for(int i=0;i<n;i++)
      {    
          if(lmax[i]<rmax[i])
          store=store+(lmax[i]-arr[i]);
           else
           store=store+(rmax[i]-arr[i]);
      }  
      return store;   
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends