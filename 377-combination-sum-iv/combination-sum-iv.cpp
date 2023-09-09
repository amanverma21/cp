class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // if(nums.size()==1 && nums[0] > target) return 0;
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for(int i=1;i<=target;i++){
            for(int it:nums){
                if(i-it >= 0) dp[i] += dp[i-it];
            }
        }
        return dp[target];
    }
};