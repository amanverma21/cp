class Solution {
public:
    int n;
    set<vector<int>> ans;               
    void func(int ind, vector<int>&nums){
        if(ind==n){
            ans.insert(nums);
            return;
        }
        func(ind+1, nums);
        for (int j=ind+1; j<n; j++){
            if (nums[ind]!=nums[j]){
                swap(nums[ind], nums[j]);
                func(ind+1, nums);
                swap(nums[ind], nums[j]);
            } 
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        func(0,nums);
        return vector<vector<int>>(ans.begin(), ans.end());

    }
};