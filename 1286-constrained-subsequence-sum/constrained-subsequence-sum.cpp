class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // int n = nums.size();
        // vector<int> dp(n, 0);
        // int maxSum = INT_MIN;
        // for (int i = 0; i < n; i++) {
        //     dp[i] = nums[i];
        //     for (int j = max(0, i - k); j < i; j++) {
        //         dp[i] = max(dp[i], dp[j] + nums[i]);
        //     }

        //     maxSum = max(maxSum, dp[i]);
        // }

        // return maxSum;
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq;
        int maxSum = nums[0];
        dp[0] = nums[0];
        dq.push_back(0);
        for (int i = 1; i < n; ++i) {
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }
            dp[i] = (nums[i] > nums[i] + dp[dq.front()]) ? nums[i] : nums[i] + dp[dq.front()];
            maxSum = (maxSum > dp[i]) ? maxSum : dp[i];
            while (!dq.empty() && dp[i] >= dp[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return maxSum;
    }
};
