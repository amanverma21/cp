// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        map<string,int>mp;
       for(int i=0;i<n;i++)
       {
           mp[arr[i]]++;
       }
       string ans,anss;
       int y=0,z=0,c=0;
      for(auto x:mp)
      { 
          if(y<x.second)
          {
              y=x.second;
              ans=x.first;
          }
          
      }
      for(auto x:mp)
      { 
          if(x.second==y)
          {
             c++;
          }
          
      }
      for(auto x:mp)
      { 
          if(z<x.second&&x.second<y)
          {
              z=x.second;
              anss=x.first;
          }
      }
      if(c>=2)
      {
      return ans;
      }
      else
      {
          return anss;
      }
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends