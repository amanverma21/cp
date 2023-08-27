class Solution {
public:
    int Recursion(int i, vector<int> &nums,vector<int>&dp)
       	    {
       	        if (i == 0) return nums[0];
       	        if (i < 0) return 0;
                if(dp[i]!=-1) return dp[i];
       	        int pick = nums[i] + Recursion(i - 2, nums,dp);
       	        int nonPick = 0 + Recursion(i - 1, nums,dp);
       	        return dp[i]=max(pick, nonPick);
       	    }
       	int rob(vector<int> &nums)
       	{
       	    int n = nums.size();
            vector<int>dp(n,-1);
       	    return Recursion(n-1,nums,dp);
       	}
};
