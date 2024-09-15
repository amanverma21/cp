class Solution {
public:
    int findTheLongestSubstring(string s) {
        int map[26] = {1,0,0,0,2,0,0,0,4,0,0,0,0,0,8,0,0,0,0,0,16,0,0,0,0,0};
        unordered_map<int,int> um;
        um[0] = -1;
        int mask = 0,ans = 0;
        for(int i = 0;i<s.size();i++)
        {
            mask ^= map[s[i]-'a'];
            if(um.find(mask)!=um.end())
                ans = max(ans,i-um[mask]);
            else
                um[mask] = i;
        }
        return ans;
    }
};