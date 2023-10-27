class Solution {
    int solve(vector<int>& prices, int ind, int buy, vector<vector<int>>& dp) {
        if (ind == prices.size()) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if (buy) {
            profit = max(prices[ind] + solve(prices, ind + 1, 0, dp),
                         solve(prices, ind + 1, 1, dp));
        } else {
            profit = max(-prices[ind] + solve(prices, ind + 1, 1, dp),
                         solve(prices, ind + 1, 0, dp));
        }
        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, 0, dp);
    }
};

