class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int sum = 0;
        map<int,int>mp;
        set<int>st;
        // if(k==0) return nums.size();
        int j=0,mx=0,ans=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            mx = max(mx,mp[nums[i]]);
            ans = max(mx,ans);
            sum++;
            while(sum-mx>k){
                mp[nums[j]]--;
                sum--;
                mx = max(mx,mp[nums[i]]);
                j++;    
            }
        }
        return ans;
    }
};