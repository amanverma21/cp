class Solution {
public:
    bool solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind < 0) return false;  
        if(dp[ind][target] != -1) return dp[ind][target];
        bool not_take = solve(ind - 1, target, nums, dp);
        bool take = false;
        if(nums[ind] <= target){
            take = solve(ind - 1, target - nums[ind], nums, dp); 
        }
        return dp[ind][target] = take || not_take;  
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) return false;
        vector<vector<int>> dp(n, vector<int>((sum / 2) + 1, -1));
        int target = sum / 2;
        return solve(n - 1, target, nums, dp);
    }
};
