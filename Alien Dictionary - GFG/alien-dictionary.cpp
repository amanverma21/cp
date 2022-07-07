// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void topological(unordered_map<char,vector<char>> &adj,unordered_set<char> &vis,stack<char> &s,char node){
        vis.insert(node);
        for(auto i:adj[node]){
            if(!(vis.find(i)!=vis.end())){
                topological(adj,vis,s,i);
            }
        }
        s.push(node);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        unordered_map<char,vector<char>> adj;
        string a,b;
        for(int i=0;i<N-1;i++){
            a=dict[i];
            b=dict[i+1];
            int aa=0,bb=0;
            while(aa<a.size() && bb<b.size() && a[aa]==b[bb]){
                aa++;
                bb++;
            }
            if(aa==a.size() || bb==b.size()) continue;
            adj[a[aa]].push_back(b[bb]);
        }
        stack<char> s;
        unordered_set<char> vis;
        for(char i='a';i<'a'+K;i++){
            if(!(vis.find(i)!=vis.end())){
                topological(adj,vis,s,i);
            }
        }
        
        string ans="";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends