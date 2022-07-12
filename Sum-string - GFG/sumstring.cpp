// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    bool func(string &s,int i,int n,long long int sum,int b,long long int p){
       if(i==n){
           if(b==2 or b==1) return false;
           return true;
       }
       string t;
       long long int a=0;
       for(int j=i;j<n;j++){
           t.push_back(s[j]);
           a=(a*10)+(s[j]-48);
           if(b>1){
               if(func(s,j+1,n,p+a,b-1,a)) return true;
               continue;
           }
           if(sum==a and func(s,j+1,n,p+a,0,a)) return true;
       }
       return false;
   }
   int isSumString(string s){
       return func(s,0,s.size(),0,3,0);
   }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.isSumString(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends