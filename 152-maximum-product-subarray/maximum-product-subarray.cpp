class Solution {
public:
    int maxProduct(vector<int>& nums) {
    //     int result = nums[0];
    // for(int i=0;i<nums.size()-1;i++) {
    //     int p = nums[i];
    //     for(int j=i+1;j<nums.size();j++) {
    //        result = max(result,p);
    //        p *= nums[j];
    //     }
    //     result = max(result,p);
    // }
    // return result;
        int n = nums.size();
        int pre=1,suff=1;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(pre==0) pre=1;
            if(suff==0) suff=1;
            pre*=nums[i];
            suff*=nums[n-i-1];
            ans=max(ans,max(pre,suff));
        }
        return ans;
    }
};