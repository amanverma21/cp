class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        long long res = 0;
        long long cnt1 = 0;
        long long cnt2 = 0;
        for (auto& num : nums1) {
            ans += num;
            if (num == 0) {
                cnt1++;
                ans += 1;
            }
        }
        for (auto& num : nums2) {
            res += num;
            if (num == 0) {
                cnt2++;
                res += 1;
            }
        }
        if (ans < res && cnt1 == 0) {
            return -1;
        }
        if (res < ans && cnt2 == 0) {
            return -1;
        }
        return max(ans, res);
    }
};