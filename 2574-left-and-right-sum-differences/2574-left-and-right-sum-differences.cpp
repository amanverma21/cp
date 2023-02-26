class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int>ans;
        int sum=0;
        for(auto it:nums) sum+=it;
        int lsum=0;
        for(int i=0;i<nums.size();i++){
            int rsum=sum-(lsum+nums[i]);
            ans.push_back(abs(rsum-lsum));
            lsum+=nums[i];
        }
        return ans;
    }
};