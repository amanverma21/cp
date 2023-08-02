//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {

 

        if(A[0][0]==0 || A[X][Y]==0)

        return -1;

        

        queue<pair<int,int>>q;

       q.push({0,0});

       

       int ans=-1;

       vector<pair<int,int>>dir{{-1,0},{0,-1},{1,0},{0,1}};

       

       while(!q.empty())

       {

           ans++;

           int n=q.size();

           while(n--)

           {

           auto curr=q.front();

           q.pop();

           

          if(curr.first==X and curr.second==Y)

              return ans;

           for(auto i:dir)

           {

               int nr=curr.first+i.first;

               int nc=curr.second+i.second;

               if(nr>=0 and nr<N and nc>=0 and nc<M and A[nr][nc])

               {

                A[nr][nc]=0;

                q.push({nr,nc});

               }

           }

           }

       }

 

        return -1;

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends