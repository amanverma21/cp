class Solution {
public:
    bool solve(int ind, int target, vector<int>&arr,vector<vector<int>>& dp){
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool not_take=solve(ind-1,target,arr,dp);
    bool take = false;
    if(arr[ind]<=target){
        take=solve(ind-1,target-arr[ind],arr,dp);
    } 
    return dp[ind][target] = take | not_take;
}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        vector<vector<int>>dp(n+1, vector<int>(sum/2+1,-1));
        return solve(n-1, sum/2, nums, dp);
    }
};