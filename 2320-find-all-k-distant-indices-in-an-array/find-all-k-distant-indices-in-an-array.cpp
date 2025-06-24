class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        int n = nums.size();
        while (i < n && j < n) {
            if (nums[j] != key) {
                j++;
            } else {
                if (abs(i - j) <= k) {
                    ans.push_back(i);
                    i++;
                } else if (i <= j)
                    i++;
                else
                    j++;
            }
        }
        return ans;
    }
};