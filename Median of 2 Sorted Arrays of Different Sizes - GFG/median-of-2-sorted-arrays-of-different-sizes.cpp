// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
      vector<int>ans;
       int i=0,j=0;
       int a1,a2;
       a1 = array1.size();
       a2 = array2.size();
       while(i<a1 && j<a2)
       {
           if(array1[i]<array2[j])
           {
               ans.push_back(array1[i]);
               i++;
           }
           else
           {
               ans.push_back(array2[j]);
               j++;
           }
       }
       if(i!=a1)
       {
           for(int k=i;k<a1;k++)
           {
               ans.push_back(array1[k]);
           }
       }
       if(j!=a2)
       {
           for(int k=j;k<a2;k++)
           {
               ans.push_back(array2[k]);
           }
       }
       double p;
      if(ans.size()%2==0)
      {
          p = ans[(ans.size())/2] + ans[(ans.size())/2 - 1];
          return p/2;
      }
      p = ans[(ans.size())/2];
      return p;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends