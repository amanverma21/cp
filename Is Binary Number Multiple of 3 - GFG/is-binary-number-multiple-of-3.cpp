//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int sum=0, mul=1, n=s.size();
	     for(int i=n-1; i>=0; i--){
	         int num = 0;
	         if(s[i]=='1') num = 1;
	         sum = (sum + num*mul)%3;
	         mul = (mul*2)%3;
	     }
	     if(!sum) 
	     return 1;
	     return 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends