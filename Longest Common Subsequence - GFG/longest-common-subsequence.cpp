//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    //top down
    // int dp[1001][1001];
    // int lc(int x, int y, string s1, string s2){
    //     if(x==-1 || y==-1) 
    //   return 0;   
    //   if(dp[x][y]!=-1)
    //   return dp[x][y];
    //   if(s1[x]==s2[y]){
    //       return dp[x][y]= 1+lc(x-1,y-1,s1,s2);
    //   }
    //   else{
    //       return dp[x][y]=max(lc(x,y-1,s1,s2),lc(x-1,y,s1,s2));
    //   }
    // }
    
    int lcs(int n, int m, string S1, string S2)
    {
        // your code here
        //Recursive  tle aa
    //   if(x==0 || y==0) 
    //   return 0;    
    //   if(s1[x-1]==s2[y-1]){
    //       return 1+lcs(x-1,y-1,s1,s2);
    //   }
    //   else{
    //       return max(lcs(x,y-1,s1,s2),lcs(x-1,y,s1,s2));
    //   }
        // memset(dp,-1,sizeof(dp));
        // return lc(x-1,y-1,s1,s2);
        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        int ans=dp[0][0];
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(S1[i-1]==S2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    // ans=max(dp[i][j],ans);
                }
                else
                {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
        
    }
    
};



//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends