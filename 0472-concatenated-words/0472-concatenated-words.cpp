class Solution {
public:
    bool dfs(string &s, unordered_map<string,int>&mp,int index){
        if(index==s.size()) return true;
        string temp="";
        for(int i=index;i<s.size();i++){
            temp+=s[i];
            if(mp[temp]>0&&dfs(s,mp,i+1)) return true;
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }
        vector<string>ans;
        for(auto it:words){
            mp[it]--;
            if(dfs(it,mp,0)){
                ans.push_back(it);
            }
            mp[it]++;
        }
        return ans;
    }
};