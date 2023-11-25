// class Solution {
// public:
//     vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
//         int n = nums.size();
//         std::vector<int> ans(n);
//         for (int i = 0; i < n; ++i) {
//             int leftSum = 0, rightSum = 0;
//             for (int j = 0; j < i; ++j) {
//                 leftSum += nums[i] - nums[j];
//             }
//             for (int j = i + 1; j < n; ++j) {
//                 rightSum += nums[j] - nums[i];
//             }
//             ans[i] = leftSum + rightSum;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n, 0);
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            preSum[i] = preSum[i - 1] + nums[i];
        for (int i = 0; i < n; i++) {
            int leftSum = i * nums[i] - (i > 0 ? preSum[i - 1] : 0);
            int rightSum = (preSum[n - 1] - preSum[i]) - (n - 1 - i) * nums[i];
            nums[i] = leftSum + rightSum;
        }
        return nums;
    }
};