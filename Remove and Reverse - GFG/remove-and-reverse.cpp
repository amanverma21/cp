//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        // code here
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int i=0,j=n-1,k=0;
        string ans1="",ans2="";
        while(i<=j){
            if(k%2==0){
                if(mp[s[i]]>1){
                    mp[s[i]]--;
                    k++;
                }
                else{
                    ans1+=s[i];
                }
                i++;
            }
            else{
                if(mp[s[j]]>1) {
                    mp[s[j]]--;
                    k++;
                }
                else {
                    ans2+=s[j];
                }
                j--;
            }
        }
         reverse(ans2.begin(),ans2.end());
        ans1=ans1+ans2;
        if(k%2==0) return ans1;
        reverse(ans1.begin(),ans1.end());
        return ans1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends