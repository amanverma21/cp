class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2, s;
        int n = nums1.size();
        for (int x : nums1) {
            s1.insert(x);
            s.insert(x);
        }
        for (int x : nums2) {
            s2.insert(x);
            s.insert(x);
        }
        int ans = min(min(n/2, (int)s1.size()) + min(n/2, (int)s2.size()),(int) s.size());
         
        return ans;
    }
};