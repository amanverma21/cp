class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<long long,long long>> mp(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            mp[i] = make_pair(nums[i],i);
        }
        sort(mp.begin(),mp.end());
        vector<bool> b(nums.size(),false);
        for(int i=0;i<mp.size();i++)
        {
            int x = mp[i].second;
            if(b[x]==false)
            {
                if((x-1)>=0) b[x-1] =true; 
                if((x+1)<nums.size()) b[x+1] = true;
            }
        }
        long long sum = 0;
        for(int i=0;i<b.size();i++)
        {
            if(b[i]==0) sum+=nums[i];
        }
        return  sum;
    }
};