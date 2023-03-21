class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long cnt=0,ans=0;
        for(int n:nums){
            if(n==0)
                cnt+=++ans;
            else
                ans=0;
        }
        return cnt;
    }
};