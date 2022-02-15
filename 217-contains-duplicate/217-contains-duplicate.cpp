class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> verge;
    for(int it:nums)
        verge.emplace(it);
    return !(verge.size() == nums.size());
    }
};