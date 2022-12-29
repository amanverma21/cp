//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &ast) {
        // code here
        stack<int> s;
        for(int i : ast) {
            int f = 0;
            while(s.size() && s.top() > 0 && i < 0) {
                if(abs(s.top()) < abs(i)) s.pop();
                else if(abs(s.top()) == abs(i)) {s.pop(); f = 1; break;}
                else {f = 1; break;}
            }
            if(!f) s.push(i);
        }
        vector<int> ans;
        while(s.size()) 
        ans.push_back(s.top()), s.pop();
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends