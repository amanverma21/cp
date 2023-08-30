class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0;
        int current_min = nums[n-1];
        for(int i = n-2;i>=0;i--){
            if(nums[i]>current_min){
                int steps = ceil(nums[i]/(1.0 * current_min)) - 1;
                ans+=steps;
                current_min = min(current_min,nums[i]/(steps+1));
            }
            else
                current_min = nums[i];
        }
        return ans;

    }
};