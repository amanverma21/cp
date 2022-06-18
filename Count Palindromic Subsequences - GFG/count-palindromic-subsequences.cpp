// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
        long long m = 1000000007;
       int n = str.size();
       long long int dp[n+1][n+1];
      
      for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        dp[i][j]=0;
        if(i==j)
           dp[i][j]=1;
      }
      }
        
     
  
     long long int j=1,k=0,i=0;
     while(j<n)
     {
         k=j;
         i=0;
         while(k<n)
         {
          // cout<<"value of i is "<<i<<" value of j is "<<k<<endl;
             if(str[i]==str[k])
               dp[i][k]=(1+dp[i+1][k]+dp[i][k-1])%m;
              
             else
               dp[i][k]=(m+dp[i+1][k]+dp[i][k-1]-dp[i+1][k-1])%m;
               
             i++;
             k++;
         }
         j++;
     }
     return dp[0][n-1]; 
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends