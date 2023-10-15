class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<long long> money(n + 1, INT_MAX);
        money[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = n; j > 0; j--) {
                money[j] = min(money[j], money[max(j - time[i] - 1, 0)] + cost[i]);
            }
        }
        return (int)money[n];
    }
};