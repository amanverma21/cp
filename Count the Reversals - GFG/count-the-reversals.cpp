// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
     int t=0;
   int m=0;
   for(int i=0;i<s.size();i++){
       if(s[i]=='{'){
           t++;
       }else{
           t--;
       }
       if(t<0){
           t=t+2;
           m++;
       }
   }
   if(t%2==0){
       return m+t/2;
   }else{
       return -1;
   }
}