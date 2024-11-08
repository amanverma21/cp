class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorsum=0;
        vector<int>v;
        int ns=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            xorsum=xorsum^nums[i];
        }
        for(int j=0;j<ns;j++){ 
        int n=0;
        for(int i=0;i<maximumBit;i++)
        {
            n=n|(1<<i);
        }
        int k=n^xorsum;
        v.push_back(k);
        int x=nums.back();
        nums.pop_back();
        xorsum=xorsum^x;
        }
        return v;
    }
};