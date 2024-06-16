class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int n2=nums.size();
        long long maxreach=0;
        int ans=0;
        for(int i=0;i<n2;i++){
            while(nums[i]>(maxreach+1)){
                maxreach=2*maxreach+1;
                ans++;
                if(maxreach>=n){
                    return ans;
                }
            }
            maxreach+=nums[i];
            if(maxreach>=n){
                return ans;
            }
        }
        while(maxreach<n){
            maxreach=2*maxreach+1;
            ans++;
        }
        return ans;
    }
};