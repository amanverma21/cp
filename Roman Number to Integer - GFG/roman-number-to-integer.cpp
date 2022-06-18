// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        
        // code here
        
         int sr, n=s.length(),sum=0,temp=INT_MAX;
       for(int i=0; i<s.length(); i++)
       {
           if(i==n-2 && s[i]=='I' && s[i+1]=='V') 
           {
               sr=4;
               sum+=sr;
               break;
           }
           else if(i==n-2 && s[i]=='I' && s[i+1]=='X') 
           {
               sr=9;
               sum+=sr;
               break;
           }
           else if(s[i]=='I')  sr=1;
           else if(s[i]=='V') sr=5;
           else if(s[i]=='X') sr=10;
           else if(s[i]=='L') sr=50;
           else if(s[i]=='C') sr=100;
           else if(s[i]=='D') sr=500;
           else if(s[i]=='M') sr=1000;
           sum+=sr;
           if(temp<sr) sum -= temp*2;
           temp = sr;
       }
       return sum;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends