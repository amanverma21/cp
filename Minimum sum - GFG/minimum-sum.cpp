// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        string s;
       sort(arr,arr+n);
       string s1,s2;
       int i=0,j=1;
       while(i<n && j<=n)
       {
           if(arr[i]!=0)
           s1+=to_string(arr[i]);
           if(j<n && arr[j]!=0)
           s2+=to_string(arr[j]);
           i+=2;
           j+=2;
       }
       if(s1.length()>0 && s2.length()>0){
       i=s1.length()-1,j=s2.length()-1;
       int d=0;
       while(i>=0 && j>=0)
       {
           int r=stoi(s1.substr(i,1))+stoi(s2.substr(j,1))+d;
           d=r/10;
           r=r%10;
           s+=to_string(r);
           i--,j--;
       }
       if(i>=0)
       {
           int r=stoi(s1.substr(i,1))+d;
           d=r/10;
           r=r%10;
           s+=to_string(r);
           i--;
       }
       if(j>=0)
       {
           int r=stoi(s2.substr(j,1))+d;
           d=r/10;
           r=r%10;
           s+=to_string(r);
           j--;
       }
       if(d!=0)
       s+=to_string(d);
       reverse(s.begin(),s.end());
       return s;
       }
       else if(s1.length()>0)
       return s1;
       else if(s2.length()>0)
       return s2;
       else
       return s+="0";
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends