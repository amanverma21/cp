// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        stack<pair<char, int>> q;
        int y = 1;
        if(k==1) return "";
        for(int i = 0; i < s.size(); ++i){
            if(q.empty()){
                q.push({s[i], 1});
            }else{
                if(q.top().first==s[i]){
                    q.push({s[i], q.top().second+1});
                }
                else{
                    q.push({s[i], 1});
                }
                if(q.top().second==k){
                    y=k;
                    while(y--){
                        q.pop();
                    }
                }
            }
        }
        s = "";
        while(!q.empty()){
            s.push_back(q.top().first);
            q.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }


};

// { Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}  // } Driver Code Ends