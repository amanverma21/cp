class Solution {
public:
    static bool cmp(string &s1, string &s2){
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        // int n = words.length();
        sort(words.begin(),words.end(),cmp);
        int ans=0;
        unordered_map<string,int>mp;
        for(string it:words){
            int longest=0;
            for(int i=0;i<it.length();i++){
                string new_str=it;
                new_str.erase(i,1);
                longest = max(longest,mp[new_str]+1);
            }
            mp[it] = longest;
            ans = max(ans,longest);
        }
        return ans;
    }
};


 