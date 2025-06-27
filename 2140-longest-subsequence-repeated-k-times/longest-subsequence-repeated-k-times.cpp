class Solution {
public:
    string dfs(string &cur, vector<int> &times, string &s, int k, int maxLen) {
        if (cur.size() == maxLen) {
            int idx = 0, cnt = 0;
            for (auto &x: s) {
                if (cur[idx] == x) idx += 1;
                if (idx == maxLen) {
                    idx = 0;
                    cnt += 1;
                }
            }
            if (cnt >= k) return cur;
            return "";
        }
        for (int i = 25; i >= 0; i--) {
            if (times[i] == 0) continue;
            cur.push_back((char)i + 'a');
            times[i] -= 1;
            string res = dfs(cur, times, s, k, maxLen);
            if (res.size() > 0) return res;
            cur.pop_back();
            times[i] += 1;
        }
        return "";
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (auto &x: s) cnt[x - 'a'] += 1;
        vector<int> times(26, 0);
        for (int i = 0; i < 26; i++) {
            times[i] = cnt[i] / k;
        }
        string cur = "";
        for (int len = n / k; len >= 1; len--) {
            string res = dfs(cur, times, s, k, len);
            if (res.size() > 0) return res;
        }
        return "";
    }
};