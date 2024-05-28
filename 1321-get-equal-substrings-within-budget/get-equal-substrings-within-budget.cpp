class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + abs(s[i] - t[i]);
        int l = 0, r = n;
        while (l < r) {
            int m = l + (r - l + 1) / 2;
            if (check(n, prefix, maxCost, m)) l = m;
            else r = m - 1;
        }
        return l;
    }
private:
    bool check(int n, vector<int>& prefix, int maxCost, int length) {
        for (int i = 0; (i + length) <= n; i++) {
            int cost = prefix[i + length] - prefix[i];
            if (cost <= maxCost) return true;
        }
        return false;
    }
};