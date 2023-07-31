class Solution {
public:
    // int singleNumber(vector<int>& nums) {
    //     unordered_map<int,int>mp;
    //     for(int i=0;i<nums.size();i++) mp[nums[i]]++;
    //     for(auto it:mp){
    //         if(it.second==1) 
    //         return it.first;
    //     }
    //     return -1;
    // }
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i = 0; i < nums.size(); i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};