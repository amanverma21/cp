class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j>=0;j--)
            {
                int pro;
                if(j)
                {
                    pro=max(a[i]+dp[i+2][0],0+dp[i+1][1]);
                }
                else
                {
                    pro=max(-a[i]+dp[i+1][1],0+dp[i+1][0]);
                }
                dp[i][j]=pro;
            }
        }
        return dp[0][0];
        
    }
};