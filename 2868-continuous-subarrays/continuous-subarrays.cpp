class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> maxD, minD;
        long long  result = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            while (!maxD.empty() && nums[maxD.back()] <= nums[r]) {
                maxD.pop_back();
            }

            maxD.push_back(r);
            while (!minD.empty() && nums[minD.back()] >= nums[r]) {
                minD.pop_back();
            }
            minD.push_back(r);


            while (!maxD.empty() && !minD.empty() && (nums[maxD.front()] - nums[minD.front()] > 2)) {
                if (maxD.front() == l) maxD.pop_front();
                if (minD.front() == l) minD.pop_front();
                l++;
            }
            result += (r - l + 1);
        }
        return result;
    }
};