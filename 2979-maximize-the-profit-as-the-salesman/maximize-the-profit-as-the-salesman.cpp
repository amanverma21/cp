
class Solution {
public:
    int pickornotpick(vector<vector<int>>& offers, int target){
        int low = 0, high = offers.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(offers[mid][0]>target){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

    int solve(int index, vector<vector<int>>& offers, vector<int>& dp){
        if(index>=offers.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int ans = pickornotpick(offers,offers[index][1]);
        int res = 0;
        res = offers[index][2] + solve(ans, offers, dp);
        int rem = solve(index+1, offers, dp);
        return dp[index] = max(res,rem);
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(offers.size(), -1);
        int ans=0;
        sort(offers.begin(),offers.end());
        return solve(0,offers,dp);
    }
};
