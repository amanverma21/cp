class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(),left=0,zeros=0,ans=0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeros++;
            }
            while (zeros > 1) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            ans = max(ans, i - left + 1 - zeros);
        }
        return (ans == n) ? ans - 1 : ans;
    }
};