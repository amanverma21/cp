class Solution {
public:
    #define ll long long
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll l=0, r=0;
        ll cnt=0;
        ll n = nums.size();

        long long sum=0, maxi=0;
        map<int, ll> mp;
        for(r=0; r<n; r++){
            sum+=nums[r];
            mp[nums[r]]++;

            if(r-l+1 == k){
                if(mp.size() == r-l+1){
                    maxi = max(sum ,maxi);
                }
                sum-=nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
        }
        return maxi;
    }
};