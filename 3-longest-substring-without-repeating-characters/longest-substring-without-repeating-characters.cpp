class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int char_count[256] = {0};
        for (int l = 0, r = 0; r < n; r++) {
            char_count[s[r]]++;
            while (char_count[s[r]] > 1) {
                char_count[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
    
};