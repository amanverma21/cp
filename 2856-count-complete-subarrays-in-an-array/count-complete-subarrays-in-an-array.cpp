class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> unique(nums.begin(), nums.end());
        int ans = unique.size();
        
        unordered_map<int, int> freq;
        int left = 0, count = 0, distinct = 0;
        
        for (int right = 0; right < n; ++right) {
            if (++freq[nums[right]] == 1) {
                ++distinct;
            }
            
            while (distinct == ans) {
                count += (n - right); 
                if (--freq[nums[left]] == 0) {
                    --distinct;
                }
                ++left;
            }
        }
        
        return count;
    }
};