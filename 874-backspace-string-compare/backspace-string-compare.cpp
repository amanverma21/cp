class Solution {
public:
    string solve(const string& input) {
        string ans;
        for (char ch : input) {
            if (ch == '#') {
                if (!ans.empty()) {
                    ans.pop_back();
                }
            } else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        return solve(s) == solve(t);
    }
};
