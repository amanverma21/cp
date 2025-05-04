class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count[100] = {0};
        int ans = 0;
        for (auto& it : dominoes) {
            int a = it[0], b = it[1];
            int key = min(a, b) * 10 + max(a, b);
            ans += count[key];
            count[key]++;
        }
        return ans;
    }
};