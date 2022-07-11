// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
     int dp[n1+1][n2+1][n3+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            for(int k=1; k<=n3; k++){
                if(A[i-1] == B[j-1] && B[j-1] == C[k-1])
                    dp[i][j][k] = 1+dp[i-1][j-1][k-1];
                else{
                    int a = dp[i-1][j-1][k];
                    int b = dp[i-1][j-1][k-1];
                    int c = dp[i][j-1][k];
                    int d = dp[i][j-1][k-1];
                    int e = dp[i-1][j][k];
                    int f = dp[i-1][j][k-1];
                    int g = dp[i][j][k];
                    int h = dp[i][j][k-1];
                    dp[i][j][k] = max({a,b,c,d,e,f,g,h});
                }
            }
        }
    }
    return dp[n1][n2][n3];
}