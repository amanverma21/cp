class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        vector<int>ans;
        // if()
        // for(auto it:mp){
        //     if(it.second>=k)
        //     ans.push_back(it.first);
        // }
        // return ans;
        priority_queue<pair<int,int>>pq;
        for(auto it:mp)
            pq.push(make_pair(it.second,it.first));
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};