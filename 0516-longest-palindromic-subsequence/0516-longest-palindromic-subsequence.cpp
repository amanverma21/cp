class Solution {
public:
    int longestPalindromeSubseq(string a) {
        string b=a;
        reverse(b.begin(),b.end());
        int n=a.length();
        // int m=b.length();
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
            if(i==0 || j==0)
            dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][n];
    }
};