class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=n-1;
        sort(nums.begin(), nums.end());
        auto it=unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        int m=nums.size(), k=n-m;
        queue<int> q;
        for (int i=0; i<m; i++) {
            while (!q.empty() && nums[i]-q.front()>= n)
                q.pop();
            
            q.push(nums[i]);
            ans = min(ans, n-(int)(q.size()));
        } 
        return ans;
    }
};