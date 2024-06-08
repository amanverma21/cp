class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        nums[0]=nums[0]%k;
        for(int i=1;i<nums.size();i++){
            nums[i]=(nums[i-1]+nums[i]%k)%k;
        }
        map<int,int>mp;
        mp.insert({nums[0],0});
        for(int i=1;i<nums.size();i++){
            if(nums[i]==0)
                return 1;
            else if(mp.find((nums[i]-k+k)%k)!=mp.end()){
                if(i-mp[(nums[i]-k+k)%k]>1)
                    return 1;
            }
            mp.insert({nums[i],i});
    }
        return false;
    }
};