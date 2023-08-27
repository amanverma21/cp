class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length()>magazine.length()) return false;
        unordered_map<char,int>mp1,mp2;
        // for(int i=0;i<)
        for(char it :magazine){
            mp1[it]++;
        }
        for(char c:ransomNote){
            if(mp1.find(c)!=mp1.end() && mp1[c]>0)
                mp1[c]--;
            else
                return false;
        }
        return true;
    }
};