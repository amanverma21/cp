//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string a, string b)
    {
        //code here.
        int n = a.length() , m = b.length();
        if(n != m)
            return -1;
        unordered_map<char,int> mp;
        for(int i = 0; i < n; i++){
            mp[a[i]]++;
            mp[b[i]]--;
        }
        for(auto it: mp){
            if(it.second < 0)
                return -1;
        }
        int count = 0 , j = n-1;
        for(int i = n-1; i >= 0; i--){
            if(b[j] != a[i]){
                count++;
            }
            else j--;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends