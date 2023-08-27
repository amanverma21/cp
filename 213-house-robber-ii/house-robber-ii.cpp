class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 1) {
            return nums[start];
        }
        vector<int> dp(n);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(nums[start + i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        
        int max1 = robRange(nums, 0, n - 2);  // Exclude the last house
        int max2 = robRange(nums, 1, n - 1);  // Exclude the first house
        
        return max(max1, max2);
    }
};
