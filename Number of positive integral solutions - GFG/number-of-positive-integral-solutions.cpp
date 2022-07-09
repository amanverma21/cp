// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    long ncr(long n, long r){
    if(r == 0)
        return 1 ;
    return n * ncr(n-1,r-1) / r ;
}
long posIntSol(string& s){
    int n = 1, k = 0 ;
    for(int i=0; i<s.size() ; i++){
        if(s[i] == '+')
            n++ ;
        else if(s[i] == '='){
            i++ ;
            while(i<s.size())
                k *= 10, k += s[i++]-'0' ;
        }
    }
    if(n > k)
        return 0 ;
    if(n == k)
        return 1 ;
    
    return ncr(k-1,n-1) ;
}
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends