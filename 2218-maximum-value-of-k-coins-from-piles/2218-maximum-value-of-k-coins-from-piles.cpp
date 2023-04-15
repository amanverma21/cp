class Solution {
public:
      int dp[1001][2001];
    int solve(vector< vector< int>> &p, int k, int i)
        {
            if (i >= p.size())
                return 0;
            
            if(dp[i][k]!=-1) 
                return dp[i][k];
            int maxa=0;
            maxa= max(maxa, solve(p, k, i+1));
        
            for(int j=0; j<p[i].size(); j++)
            {
                if(j+1<=k)
                    maxa= max(maxa, p[i][j]+ solve(p, k-j-1, i+1));
                else
                {
                    break;
                }
            }
            
            return  dp[i][k]=maxa;
        }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
         for(int i=0; i<piles.size(); i++)
            for(int j=1; j<piles[i].size(); j++)
                piles[i][j]= piles[i][j]+ piles[i][j-1];
        
        int n=piles.size();
        for(int i=0;i<piles.size()+1;i++)
            for(int j=0;j<=k;j++)
                dp[i][j]=-1;
        return solve(piles, k, 0);       
    }
};