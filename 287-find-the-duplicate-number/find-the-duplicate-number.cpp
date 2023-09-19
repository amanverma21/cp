class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>ans;
        int res=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        for (auto pair : mp) {
        if (pair.second > 1) 
            res=pair.first;
        }
        return res;
    }
};