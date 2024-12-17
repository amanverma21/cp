class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        stack<pair<char, int>> ref;
        for (int i = 0; i < 26; i++) {
            if (cnt[i])
                ref.push({'a' + i, cnt[i]});
        }

        string ans = "";

        while (ref.size()) {

            auto it = ref.top();
            ref.pop();

            int n = min(it.second, repeatLimit);
            string temp(n, it.first);
            ans += temp;
            it.second -= n;

            if (it.second) {

                if (ref.empty())
                    break;

                auto e = ref.top();
                ref.pop();
                string a(1, e.first);
                e.second--;
                ans += a;

                if (e.second)
                    ref.push(e);
                ref.push(it);
            }
        }

        return ans;
    }
};