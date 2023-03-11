//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int num, vector<int> &arr, vector<vector<int>> &q) {
        // code here
        vector<int> ans;
        int count;
        int left, right, k;
        unordered_map<int, int> map;
        for(int i=0; i<num; i++){
            map.clear();
            left = q[i][0];
            right = q[i][1];
            k = q[i][2];
            count = 0;
            for(int j=n-1; j>=left; j--){
                map[arr[j]]++;
                if(j >= left && j <= right && map[arr[j]] == k){
                    count++;
                }
            }
        ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends