class Solution {
public:
    int solver(int cap,vector<int> &p,int ind,bool buy,bool sell,vector<vector<vector<int>>> &dp){
       if(cap==0)return 0;
       if(ind==p.size())return 0; 
        if(dp[ind][cap][buy]!=-1)return dp[ind][cap][buy];
        if(buy){
            return dp[ind][cap][buy]=max(-p[ind]+solver(cap,p,ind+1,0,1,dp),solver(cap,p,ind+1,1,0,dp));
        }else{
            return dp[ind][cap][buy]=max(+p[ind]+solver(cap-1,p,ind+1,1,0,dp),solver(cap,p,ind+1,0,1,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (k+1, vector<int> (2,-1)));
        return solver(k,prices,0,1,0,dp);
    }
};