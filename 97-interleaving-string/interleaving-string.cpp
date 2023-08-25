class Solution {
public:
    int dp[1001][1001];
    bool solve(string s1, string s2, string s3, int n, int m, int ans){
        if(ans==0) return true;
        if(dp[n][m]!=-1) return dp[n][m];
        int a,b;
        a=b=0;
        if(n-1>=0 && s1[n-1]==s3[ans-1]) a=solve(s1,s2,s3,n-1,m,ans-1);
        if(m-1>=0 && s2[m-1]==s3[ans-1]) b=solve(s1,s2,s3,n,m-1,ans-1);
        return dp[n][m]=a or b;

    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), ans = s3.length(); 
        if( n + m != ans)
            return false;
        dp[n][m];
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,s3,n,m,ans);

    }
};