//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
         int cnt_l=0,cnt_u=0;
        unordered_map<int,int> mp;   
        
        mp[0]++;
        int ans=0;
        for(auto x:S){
            if(x>='a' && x<='z'){
                cnt_l++;
            }
            else{
                cnt_u++;
            }
            ans+=mp[cnt_l-cnt_u];
            mp[cnt_l-cnt_u]++;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends