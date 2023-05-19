class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        for(auto it:nums)
            s.insert(it);
        // cout<<st.size();
        int ans = s.size();
        nums.clear();
        for(auto i:s)
        {
           nums.push_back(i);
        }
        return ans;
    }
};