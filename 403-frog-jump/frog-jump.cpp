class Solution {
public:
    unordered_map<int,int>mp;
    int dp[2000][2000];
    bool solve(int i, int k, vector<int>&stones){
        if(i==stones.size()-1) return true;
        if(dp[i][k]!=-1) return dp[i][k];
        bool k0=false,kp=false,k1=false;
        if(mp.find(stones[i]+k)!=mp.end())
            k0=solve(mp[stones[i]+k],k,stones);
        if(k>1 && mp.find(stones[i]+k-1)!=mp.end()) 
            kp=solve(mp[stones[i]+k-1],k-1,stones);
        if(mp.find(stones[i]+k+1)!=mp.end()) 
            k1=solve(mp[stones[i]+k+1],k+1,stones);
            dp[i][k] = k0 || kp || k1;
            return dp[i][k];
    }
    bool canCross(vector<int>& stones) {
         if (stones[1] - stones[0] != 1) {
            return false;
        }
        for(int i=0;i<stones.size();i++){
            mp[stones[i]] = i;
        }
        memset(dp,-1,sizeof(dp));
        return solve(1,1,stones);
    }
};