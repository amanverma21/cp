//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    int longestKSubstr(string s, int k) {
    // your code here
     int left = 0, right = 0, n = s.length(), len = -1;
        map<char,int> m;
        
        while(right < n) {
            m[s[right]]++;
            if(m.size() == k) {
                len = max(len,right-left+1);
            }
            else if(m.size() > k) {
                m[s[left]]--;
                if(m[s[left]] == 0) {
                    m.erase(s[left]);
                }
                left++;
                len = max(len,right-left+1);
            }
            right++;
        }
        
        return len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends