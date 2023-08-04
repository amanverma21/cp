class Solution {
public:
    unordered_map<string,bool>dp;
    bool solve(string s, unordered_set<string>&st){
        if(s.length()==0) return true;
        if(dp.find(s)!=dp.end()) return dp[s];
        for(int i=0;i<s.length();i++){
            string ans = s.substr(0,i+1);
            if(st.count(ans)){
                if(solve(s.substr(i+1),st)) return dp[s]=true;
            }
        }
        return dp[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
         for(auto x:wordDict){
            st.insert(x);
        }
         return solve(s,st);
    }
};