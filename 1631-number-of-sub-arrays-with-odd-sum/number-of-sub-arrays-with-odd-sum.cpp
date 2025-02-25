class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd=0,even=1;
        int res=0,ans=0,mod=1e9+7;
        for(auto x:arr){
            res+=x;
            if(res&1){
                odd++;
                ans=(ans+even)%mod;
            }else{
                even++;
                ans=(ans+odd)%mod;
            }
        }

        return ans;
    }
};