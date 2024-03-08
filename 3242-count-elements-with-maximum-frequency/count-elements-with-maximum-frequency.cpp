class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        for(int i = 0; i < nums.size();i++){
            mp[nums[i]]++;
        }
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            maxi = max(maxi,mp[nums[i]]);
        }
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]]==maxi){
                cnt++;
            }
        }
        return cnt;
    }
};