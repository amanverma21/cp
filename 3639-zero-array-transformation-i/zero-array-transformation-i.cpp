class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n, 0);
        for(auto &q : queries){
            int l = q[0], r = q[1];
            diff[l] += 1;
            if(r+1 < n) diff[r+1] -= 1;
        }
        int preSum = 0;
        for(int i=0; i<n; i++){
            preSum += diff[i];
            if(nums[i] > preSum) return false;
        }
        return true;
    }
};