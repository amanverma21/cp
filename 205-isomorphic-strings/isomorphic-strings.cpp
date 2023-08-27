class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        set<char>x;
        for(int i=0;i<s.length();i++){
            if(mp.count(s[i])){
                if(mp[s[i]]!=t[i])
                    return false;
            }
            else{
                if(x.count(t[i]))
                    return false;
                else{
                    mp[s[i]]=t[i];
                    x.insert(t[i]);
                }
            }   
        }
        return true;
    }
};