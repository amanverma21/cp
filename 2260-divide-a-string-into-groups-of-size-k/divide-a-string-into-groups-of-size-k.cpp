class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        string ans;

        for (int i = 0; i < s.length(); i++) {
            ans += s[i];
            if (ans.length() == k) {
                res.push_back(ans);
                ans.clear();
            }
        }
        if (!ans.empty()) {
            while (ans.length() < k) {
                ans += fill;
            }
            res.push_back(ans);
        }
        return res;
    }
};