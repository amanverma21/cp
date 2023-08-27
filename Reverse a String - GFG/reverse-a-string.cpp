//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
        // string ans="";
        // int n=str.length();
        // for(int i=n-1;i>=0;i--){
        //     ans.push_back(str[i]);
        // }
        // return ans;
        
        stack<char>st;
        for(char x:str){
            st.push(x);
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends