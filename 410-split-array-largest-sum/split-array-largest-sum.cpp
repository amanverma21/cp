class Solution {
public:

    int func(vector<int>& nums, int sum){
        int largest = 1;
        long long sumPages = 0;
        for(int i=0;i<nums.size();i++){
            if(sumPages + nums[i] <= sum){
                sumPages += nums[i];
            }
            else{
                largest++;
                sumPages = nums[i];
            }
        }
        return largest;
    }

    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int sum = func(nums,mid);
            if(sum > m)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};