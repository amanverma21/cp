class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n+1,n);
        dp[0] = 0;
        for(int i=0;i<n;i++){
            for(auto it:dictionary){
                if(s.substr(i,it.size())==it){
                    dp[i+it.size()] = min(dp[i+it.size()],dp[i]);
                }
            }
            dp[i+1] = min(dp[i+1], dp[i]+1);
        }
        return dp.back();
    }
};