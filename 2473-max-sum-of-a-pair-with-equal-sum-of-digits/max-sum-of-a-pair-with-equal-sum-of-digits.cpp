class Solution {
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,stack<int>>m;
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            string a=to_string(nums[i]);
            int sum=0;
            for(auto it:a){sum+=(it-'0');}
            if(m.find(sum)!=m.end()){
                auto top=m[sum].top();
                ans=max(ans,nums[i]+nums[top]);
                m[sum].push(i);
            } else {
                m[sum].push(i);
            }
        }
        return ans;
    }
};