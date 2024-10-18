class Solution {
public:
    int solve(int i, int ors, int maxi, vector<int>& nums) {
        if(i >= nums.size()){
            return (ors == maxi) ? 1 : 0;
        }
        int cnt = 0;
        cnt += solve(i + 1, ors | nums[i], maxi, nums);
        cnt += solve(i + 1, ors, maxi, nums);
        return cnt;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for(auto it: nums){
            maxi |= it;
        }
        return solve(0, 0, maxi, nums);
    }
};