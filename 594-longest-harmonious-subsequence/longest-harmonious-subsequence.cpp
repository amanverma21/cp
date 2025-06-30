class Solution {
public:
    int findLHS(vector<int>& nums) {
        int start = 0;
        int maxlen = 0;
        sort(nums.begin(), nums.end());
        for (int j = 0; j < nums.size(); j++) {
            while (nums[j] - nums[start] > 1) {
                start++;
            }
            if (nums[j] - nums[start] == 1) {
                maxlen = max(maxlen, j - start + 1);
            }
        }
        return maxlen;
    }
};