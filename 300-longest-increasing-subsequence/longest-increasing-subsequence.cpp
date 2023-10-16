class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n+1,INT_MAX);
        v[0]=INT_MIN;
        
        for(int i=0;i<n;i++){
            int ind=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
            v[ind]=min(nums[i],v[ind]);
        }
        for(int i=n;i>=0;i--){
            if(v[i]!=INT_MAX){
                return i;
            }
        }
        return 0;
    }
    
};