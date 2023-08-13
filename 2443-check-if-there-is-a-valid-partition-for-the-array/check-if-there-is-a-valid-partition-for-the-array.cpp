class Solution {
public:
    bool solve(vector<int> &nums, int i, vector<int> &dp){
        int n = nums.size();
        if(i == n) return true;
        bool ans = false;
        if(dp[i]!=-1) return dp[i];
        if(i+1<n && nums[i]==nums[i + 1]){
            ans = solve(nums, i + 2, dp);
            if(i+2<n && nums[i + 1]==nums[i + 2])
                ans = ans || solve(nums, i + 3, dp);
        }
        
        if(i+2<n && nums[i]-nums[i + 1]== -1 && nums[i + 1]-nums[i + 2]== -1)
            ans = ans || solve(nums, i + 3, dp);

        return dp[i]=ans;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return nums[0] == nums[1];
        vector<int>dp(n,-1);
        return solve(nums, 0, dp);
    }
};
