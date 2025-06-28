class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({i,nums[i]});
        }
        sort(arr.begin(),arr.end(),[&](const pair<int,int>a,const pair<int,int>b){
            if(a.second!=b.second)
             return a.second>b.second;
            return a.first<b.first;
        });
        vector<pair<int,int>>pr;
        for(int i=0;i<k;i++){
            pr.push_back(arr[i]);
        }
        sort(pr.begin(),pr.end());
        vector<int>ans;
        for(auto  i:pr)
            ans.push_back(i.second);
            return ans;
         
    }
};