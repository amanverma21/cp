class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n = nums.size(), i=0, j=0, ans = 0;
        map<int,int> m;
        auto it = m.begin();
        auto it1 = m.rbegin();
        
        while(j<n){
            m[nums[j]] +=1;
            it = m.begin();
            it1 = m.rbegin();
            
            if(abs(it->first-it1->first) <= limit){
                ans = max(ans, j-i+1);
            }else{
                while(abs(it->first-it1->first) > limit){
                    m[nums[i]] -=1;
                    if(m[nums[i]] == 0) m.erase(nums[i]);
                    i++;
                    it = m.begin();
                    it1 = m.rbegin();
                }
            }
            j++;
        }
        return ans;
        
    }
};