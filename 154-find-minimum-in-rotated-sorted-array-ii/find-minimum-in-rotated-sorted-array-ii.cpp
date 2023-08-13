class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int ans=INT_MAX;
        int low=0, high=n-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            // if(nums[low]<=nums[mid]){
            //     ans=min(ans,nums[low]);
            //     break;
            // }
             if(nums[low]==nums[mid] && nums[mid]==nums[high])
            {
                 ans=min(ans,nums[low]);
                low++;
                high--;
                continue;
            }
            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{
                ans=min(ans, nums[mid]);
                high=mid-1;
            }
        }
        return ans;
        // sort(nums.begin(), nums.end());
        // return nums[0];
    }
};