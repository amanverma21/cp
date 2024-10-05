class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> ans(26), res(26);
        for(char c : s1) res[c - 'a']++;
        for(int i = 0; i < s2.size(); i++) {
            ans[s2[i] - 'a']++;
            if(i >= s1.size()) ans[s2[i - s1.size()] - 'a']--;
            if(res == ans) return true;

        }
        return false;
    }
};