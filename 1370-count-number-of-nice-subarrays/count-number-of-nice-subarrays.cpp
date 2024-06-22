class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int cnt = 0, ans = 0, odd;
        unordered_map<int,int>mp;
        mp[0] = 1;
        for(auto val:nums)
        {
            if(val%2) cnt++;
            odd = cnt - k;
            if(mp.find(odd) != mp.end())
                ans += mp[odd];
            mp[cnt]++;
        }
        return ans;
    }
};